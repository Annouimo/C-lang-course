#include <stdio.h>
#include <stdbool.h>

void print_truth_table(char op1, char op2);
void print_one_line_table(bool a, bool b, char op1, char op2);
bool calc_bitwise(bool a, bool b, char op);

int main(void){
    char op[2];
    scanf("%c %c", &op[0], &op[1]);
    print_truth_table(op[0], op[1]);
    return 0;
}

void print_truth_table(char op1, char op2){
    printf("a b (a%cb)%cb\n", op1, op2);
    print_one_line_table(0, 0, op1, op2);
    print_one_line_table(0, 1, op1, op2);
    print_one_line_table(1, 0, op1, op2);
    print_one_line_table(1, 1, op1, op2);
}

void print_one_line_table(bool a, bool b, char op1, char op2){
    bool first_result = calc_bitwise(a, b, op1);
    bool final_result = calc_bitwise(first_result, b, op2);
    printf("%d %d %d\n", a, b, final_result);
}

bool calc_bitwise(bool a, bool b, char op){
    switch (op) {
        case '&':
            return a&b;
        case '|':
            return a|b;
        case '^':
            return (a^b)%2;
    }
    return 0;
}
