#include <stdio.h>

int multipy2(int number);
int divide2(int number);

int main(void){
    long long int x;
    scanf("%lld", &x);
    printf("%d %d", multipy2(x), divide2(x));
    return 0;
}

int multipy2(int number){
    return number<<1;
}

int divide2(int number){
    return number>>1;
}
