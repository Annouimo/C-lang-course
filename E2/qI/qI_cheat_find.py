def optimized(n):
    # 生成斐波那契数列，直到超过 n
    fib = [1, 1]
    while fib[-1] < n:
        fib.append(fib[-1] + fib[-2])
    
    # 需要打印的是 F_5, F_7, F_9, ... 即索引 4, 6, 8, ... (fib[0] 是 F_1)
    results = []
    for i in range(4, len(fib), 2):
        y = fib[i]
        if y < n:
            results.append(y)
        else:
            break
    
    # 按原格式输出：每 30 个换行
    for idx, val in enumerate(results):
        print(f"{val}, ", end="")
        if (idx + 1) % 30 == 0:
            print()
    if results:
        print()

if __name__ == "__main__":
    n = 30000000000
    optimized(n)