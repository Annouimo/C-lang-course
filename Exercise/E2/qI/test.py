import sys

def f(x, y):
    return x * x + y * y + 1 - 3 * x * y

sum_N = 0

def find_resolution(x, flag):
    global sum_N
    y = flag[0]
    f_start = f(x, y)
    while True:
        fx = f(x, y)
        if fx * f_start > 0:
            y += 1
        else:
            break
    if fx == 0:
        print(f"{y}, ")
        sum_N += 1
        if sum_N % 30 == 0:
            print()
        flag[0] = y
        return True
    else:
        y -= 1
        flag[0] = y
        return False

def main():
    n = 11000000000
    y = 2
    flag = [y]
    x = 2
    while flag[0] < n:
        find_resolution(x, flag)
        x += 1
    print()

if __name__ == "__main__":
    main()