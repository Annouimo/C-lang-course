#include <stdio.h>

unsigned int move(unsigned int n, unsigned int op, unsigned int x);
unsigned int move_left_1(unsigned int number);
unsigned int move_right_1(unsigned int number);
const int digit = 32;

int main(void){
    unsigned int t,n,op,x;
    scanf("%u", &t);
    for (int i = 0; i<t; i++) {
        scanf("%u%u%u", &n, &op, &x);
        printf("%u\n", move(n, op, x));
    }
    return 0;
}


unsigned int move(unsigned int n, unsigned int op, unsigned int x){
    x %= digit;
    for (int i =0; i<x; i++) {
        if (op==0) n = move_left_1(n);
        else n = move_right_1(n);
    }
    return n;
}

unsigned int move_left_1(unsigned int number){
    int high = number>>(digit-1);
    high = high & 1;
    int lows = number<<1;
    lows = lows & -2;
    return lows+high;
}

unsigned int move_right_1(unsigned int number){
    int high = number<<(digit-1);
    high = high & (1<<(digit-1));
    int lows = number>>1;
    return lows+high;
}
