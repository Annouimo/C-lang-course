#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

enum digits_group_config{
    GROUP_COUNT = 60,
    DIGITS_PER_GROUP = 18,
    GROUP_BASE = 1080,
};
static const long long int GROUP_MAX = 1000000000000000000LL;
typedef struct {
    unsigned long long int data [GROUP_COUNT];
} big_uint;

static void big_uint_group_plus(
    unsigned long long int * a_group,
    unsigned long long int * b_group,
    unsigned long long int * result_group,
    unsigned long long int * carry);
big_uint big_uint_plus(big_uint a, big_uint b);
void big_uint_print(big_uint number);
big_uint big_uint_scan(void);

int main(void){
    big_uint_print(big_uint_plus(big_uint_scan(), big_uint_scan()));
    return 0;
}

static void big_uint_group_plus(
    unsigned long long int * a_group,
    unsigned long long int * b_group,
    unsigned long long int * result_group,
    unsigned long long int * carry){
    unsigned long long int raw_plus = *a_group + *b_group + *carry;
    *result_group = raw_plus%GROUP_MAX;
    *carry = raw_plus/GROUP_MAX;
}
big_uint big_uint_plus(big_uint a, big_uint b){
    big_uint result={0};
    unsigned long long int carry = 0;
    for (size_t i = 0; i<GROUP_COUNT; i++) {
        big_uint_group_plus(&a.data[i], &b.data[i], &result.data[i], &carry);
    }
    return result;
}
void big_uint_print(big_uint number){
    unsigned long long int current_group = 0;
    bool is_first_group_printed = true;
    for (size_t i = 0; i<GROUP_COUNT; i++) {
        current_group = number.data[GROUP_COUNT-i-1];
        if (is_first_group_printed) {
            if (current_group != 0) {
                is_first_group_printed = false;
                printf("%llu", current_group);
            }
        }
        else {
            printf("%0*llu", DIGITS_PER_GROUP, current_group);
        }

    }
    if (is_first_group_printed) {
        printf("0");
    }
}

big_uint big_uint_scan(void){
    unsigned int big_uint_array[GROUP_BASE] = {0};
    unsigned int digit = 0, current_number = 0;
    while (1) {
        current_number = (unsigned int)(getchar()-'0');
        if ((current_number > 9)||(current_number<0)) {
            break;
        }
        big_uint_array[digit] = current_number;
        digit ++;
    }
    big_uint result = {.data = {0}};
    unsigned long long int base = 1;
    for (size_t i = 0; i<digit; i++) {
        result.data[i/DIGITS_PER_GROUP] += big_uint_array[digit-i-1]*base;
        base *= 10;
        if (base >= GROUP_MAX) {
            base = 1;
        }
    }
    return result;
}
