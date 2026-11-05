#include <stdint.h>
#include <stdio.h>

int main(void){
    uint64_t a,b,t;
    scanf("%llu%llu", &a, &b);
    uint64_t sum = 0;
    while (scanf("%llu", &t)!=EOF) {
        sum += t;
    }
    printf("%llu ", sum);
    uint64_t result = (a*sum)/(sum+b);
    printf("%llu", result);
    return 0;
}
