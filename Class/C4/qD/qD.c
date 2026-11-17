#include <stdio.h>
#include <stddef.h>

unsigned int calculate_life_number(unsigned long long int number);
unsigned long long int calculate_digit_sum(unsigned long long int number);

int main(void){
    unsigned int T;
    unsigned long long int a;
    scanf("%u", &T);
    for (size_t i = 0; i<T; i++) {
        scanf("%llu", &a);
        printf("%u\n", calculate_life_number(a));
    }
    return 0;
}

unsigned int calculate_life_number(unsigned long long int number){
    while (number>22) {
        number = calculate_digit_sum(number);
    }
    if (number == 22) {
        number = 0;
    }
    return number;
}

unsigned long long int calculate_digit_sum(unsigned long long int number){
    unsigned int sum_digit = 0;
    while (number>0) {
        sum_digit += number%10;
        number /= 10;
    }
    return sum_digit;
}
