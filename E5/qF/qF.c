#include <stddef.h>
#include <stdio.h>

enum {
    MAX_LIMIT_DIGIT = 20,
};

unsigned int get_digit(unsigned long long int number, unsigned int target_digit);

int main(void){
    size_t q=0;
    scanf("%zu", &q);
    unsigned long long int a=0, b=0;
    unsigned int p;
    for (size_t i = 0; i<q; i++) {
        scanf("%llu%llu%u", &a, &b, &p);
        printf("%u\n", get_digit(a+b, p));
    }
    return 0;
}

unsigned int get_digit(unsigned long long int number, unsigned int target_digit){
    unsigned int num_list_digit[MAX_LIMIT_DIGIT] = {};
    for (size_t i = 0; i<MAX_LIMIT_DIGIT; i++) {
        num_list_digit[i] = number%10;
        number/=10;
    }
    return num_list_digit[target_digit-1];
}
