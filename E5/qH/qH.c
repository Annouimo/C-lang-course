#include <stddef.h>
#include <stdio.h>

void separate_number(unsigned int number, char bracket);
void print_bracket(char reality, char hope);

int main(void){
    size_t t;
    scanf("%zu", &t);
    unsigned int n;
    for (size_t i = 0; i<t; i++) {
        scanf("%u", &n);
        separate_number(n, ' ');
        printf("\n");
    }
    return 0;
}

void separate_number(unsigned int number, char bracket){
    print_bracket(bracket, '(');
    if (bracket == ')') {
        printf("+");
    }
    if (number<=2) {
        printf("%u", number);
    }
    else if (number%2==1) {
        separate_number((number+1)/2, '(');
        separate_number((number-1)/2, ')');
    }
    else {
        separate_number((number+2)/2, '(');
        separate_number((number-2)/2, ')');
    }
    print_bracket(bracket, ')');
}

void print_bracket(char reality, char hope){
    if (reality == hope) {
        printf("%c", reality);
    }
}
