#include <stdio.h>
#include <math.h>

int find_diff_bite(unsigned long long int a, unsigned long long int b);

int main(void){
    unsigned int n;
    unsigned long long int a,b;
    scanf("%u", &n);
    for (unsigned int i = 0; i<n ; i++) {
        scanf("%llu%llu", &a, &b);
        printf("%d\n", find_diff_bite(a, b));
    }
    return 0;
}

int find_diff_bite(unsigned long long int a, unsigned long long int b){
    unsigned long long int diff_value = a^b;
    int diff_digit = log2l(diff_value)+1;
    return diff_digit;
}
