#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { double re, im; } Complex;

Complex complex_add(Complex a, Complex b) {
    Complex c = {a.re + b.re, a.im + b.im};
    return c;
}

Complex complex_sub(Complex a, Complex b) {
    Complex c = {a.re - b.re, a.im - b.im};
    return c;
}

Complex complex_mul(Complex a, Complex b) {
    Complex c = {a.re*b.re - a.im*b.im, a.re*b.im + a.im*b.re};
    return c;
}

Complex complex_div(Complex a, Complex b) {
    double den = b.re*b.re + b.im*b.im;
    Complex c = {(a.re*b.re + a.im*b.im)/den,
                 (a.im*b.re - a.re*b.im)/den};
    return c;
}

void print_zero(double number){
    char out[10000] = "0.000000";
    sprintf(out ,"%.2lf", number);
    if (out[0]=='-' && out[1]=='0' && out[2]=='.' && out[3]=='0' && out[4]=='0') {
        printf("0.00");
        return;
    }
    printf("%s", out);
}

int main(void) {
    char op;
    while (scanf(" %c", &op) == 1) {
        Complex a,b;
        scanf("%lf%lf", &(a.re), &(a.im));
        scanf("%lf%lf", &(b.re), &(b.im));
        Complex result;
        switch (op) {
            case '+':
                result = complex_add(a, b);
                break;
            case '-':
                result = complex_sub(a, b);
                break;
            case '*':
                result = complex_mul(a, b);
                break;
            case '/':
                result = complex_div(a, b);
                break;
        }
        print_zero(result.re);
        printf(" ");
        print_zero(result.im);
        printf("\n");
    }
    return 0;
}
