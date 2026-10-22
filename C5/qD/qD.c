#include <stddef.h>
#include <stdio.h>

enum{
    P = 1000000007
};

unsigned long long int f(unsigned long long int x);
unsigned long long int g(unsigned long long int x);

int main(void){
    unsigned long long int n=0, x=0;
    scanf("%llu%llu", &n, &x);
    for (size_t i = 0; i<n; i++) {
        if (i%2==0) {
            x = g(f(x));
        }
        else {
            x = f(g(x));
        }
    }
    printf("%llu", x);
    return 0;
}

unsigned long long int f(unsigned long long int x){
    return (x*x+1)%P;
}

unsigned long long int g(unsigned long long int x){
    return (2*x+1)%P;
}
