#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DATA_DIGIT 3

static int compare_function(const void *a, const void *b);
struct digit_arrangement {
    unsigned int max_number;
    unsigned int min_number;
};
static struct digit_arrangement arrange_digits(unsigned int number);

int main(void){
    unsigned int number = 0;
    struct digit_arrangement result = {0,0};
    scanf("%u", &number);
    while (number != 495) {
        result = arrange_digits(number);
        number = result.max_number - result.min_number;
        printf("%u - %u = %u\n", result.max_number, result.min_number, number);

    }
    return 0;
}

static int compare_function(const void *a, const void *b){
    return ((*(int *)a) - (*(int *)b));
}

static struct digit_arrangement arrange_digits(unsigned int number){
    unsigned int digit_array[DATA_DIGIT];
    for (size_t i = 0; i<DATA_DIGIT; i++) {
        digit_array[i] = number%10;
        number /= 10;
    }
    qsort(digit_array, DATA_DIGIT, sizeof(unsigned int), compare_function);
    struct digit_arrangement result = {0,0};
    unsigned int digit_base = 1;
    for (size_t i = 0; i<DATA_DIGIT; i++) {
        result.max_number *= 10;
        result.min_number *= 10;
        result.max_number += digit_array[DATA_DIGIT-i-1];
        result.min_number += digit_array[i];
    }
    return result;
}
