#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

enum {
    COUNT_A = 5
};

uint64_t count_numbers_less_than_n(uint64_t a[], uint64_t n, uint64_t lcm_a[]);
uint64_t bisection(
    uint64_t begin, uint64_t end,
    uint64_t target,
    uint64_t function(uint64_t a[], uint64_t variable, uint64_t lcm_n[]), uint64_t a[]
);
uint64_t gcd(uint64_t a, uint64_t b);
uint64_t lcm(uint64_t a, uint64_t b);

int main(void){
    size_t T;
    scanf("%zu", &T);
    uint64_t a[COUNT_A] = {0,2,3,5}, k;
    for (size_t i = 0; i < T; i++) {
        scanf("%llu%llu%llu%llu", &a[1], &a[2], &a[3], &k);
        printf("%llu\n", bisection(k, k*5, k, count_numbers_less_than_n, a));
    }
    return 0;
}

uint64_t bisection(
    uint64_t begin, uint64_t end,
    uint64_t target,
    uint64_t function(uint64_t a[], uint64_t variable, uint64_t lcm_n[]), uint64_t a[]
){
    uint64_t middle, value;
    uint64_t lcm_a[COUNT_A] = {lcm(a[1],lcm(a[2],a[3])),lcm(a[1], a[2]),lcm(a[2],a[3]),lcm(a[3],a[1])};
    while (1) {
        middle = (begin + end)/2;
        value = function(a, middle, lcm_a);
        if (value == target) {
            break;
        }
        else if (value > target) {
            end = middle;
        }
        else {
            begin = middle;
        }
    }
    while (value == target) {
        middle --;
        value = function(a, middle, lcm_a);
    }
    return middle + 1;
}

uint64_t count_numbers_less_than_n(uint64_t a[], uint64_t n, uint64_t lcm_a[]){

    return
        n-(n/a[1] + n/a[2] + n/a[3]
        - n/lcm_a[1] - n/lcm_a[2] - n/lcm_a[3]
        + n/lcm_a[0])
    ;
}

uint64_t gcd(uint64_t a, uint64_t b){
    if (a%b == 0) {
        return b;
    }
    return gcd(b, a%b);
}

uint64_t lcm(uint64_t a, uint64_t b){
    return a/gcd(a, b) * b;
}
