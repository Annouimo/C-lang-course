#include <stddef.h>
#include <stdio.h>

enum {
    MAX_FIBONACCI_N = 60,
};
static unsigned long long int cache[MAX_FIBONACCI_N] = {};

unsigned long long int fibonacci(unsigned long long int n, unsigned long long int a_1, unsigned long long int a_2);

unsigned long long int fibonacci_cache_read(unsigned long long int n);
void fibonacci_cache_write(unsigned long long int n, unsigned long long int value);
void fibonacci_cache_reset(unsigned long long int a_1, unsigned long long int a_2);

int main(void){
    unsigned long long int q=0,a=0,b=0,n=0;
    scanf("%llu", &q);
    for (size_t i = 0; i<q; i++) {
        scanf("%llu%llu%llu", &a,&b,&n);
        fibonacci_cache_reset(a, b);
        printf("%llu\n", fibonacci(n, a, b));
    }
    return 0;
}

unsigned long long int fibonacci(unsigned long long int n, unsigned long long int a_1, unsigned long long int a_2){
    unsigned long long int current_cache = fibonacci_cache_read(n);
    if (current_cache!=0||n==1||n==2) {
        return current_cache;
    }
    else {
        unsigned long long int value = fibonacci(n-1, a_1, a_2)+fibonacci(n-2, a_1, a_2);
        fibonacci_cache_write(n, value);
        return value;
    }
}

unsigned long long int fibonacci_cache_read(unsigned long long int n){
    if (cache[n]!=0) {
        return cache[n];
    }
    else {
        return 0;
    }
}

void fibonacci_cache_write(unsigned long long int n, unsigned long long int value){
    cache[n] = value;
}

void fibonacci_cache_reset(unsigned long long int a_1, unsigned long long int a_2){
    for (size_t i = 0; i<MAX_FIBONACCI_N; i++) {
        cache[i] = 0;
    }
    cache[1] = a_1;
    cache[2] = a_2;
}
