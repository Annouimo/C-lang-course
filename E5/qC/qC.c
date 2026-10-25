#include <stdio.h>

unsigned long long int calculate(unsigned long long int a, char op, unsigned long long int b);

int main(void){
    char op[3] = {0};
    unsigned long long int number[4] = {0};
    scanf("%llu%c%llu%c%llu%c%llu", &number[0], &op[0], &number[1], &op[1], &number[2], &op[2], &number[3]);
    printf("%llu", calculate(calculate(calculate(number[0], op[0], number[1]), op[1], number[2]), op[2], number[3]));
    return 0;
}


unsigned long long int calculate(unsigned long long int a, char op, unsigned long long int b){
    switch (op) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '&':
            return a&b;
    }
    return 0;
}
