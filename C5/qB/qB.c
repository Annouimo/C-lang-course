#include <stdio.h>

unsigned long long int Ackermann(unsigned long long int m, unsigned long long int n);

int main(void){
    unsigned long long int m=0,n=0;
    scanf("%llu%llu", &m, &n);
    printf("%lld", Ackermann(m, n));
}

unsigned long long int Ackermann(unsigned long long int m, unsigned long long int n){
    if (m==0) {
        return (n+1);
    }
    if (n==0) {
        return Ackermann(m-1, 1);
    }
    return Ackermann(m-1, Ackermann(m,n-1));
}
