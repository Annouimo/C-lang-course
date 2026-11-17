#include <stddef.h>
#include <stdio.h>

int main(void){
    unsigned int data_count = 0;
    scanf("%u", &data_count);
    unsigned long long int current_number = 0, previous_number = 0;
    unsigned int current_interval_length = 1, max_interval_length = 1;
    for (size_t i = 0; i < data_count; i++) {
        previous_number = current_number;
        scanf("%llu", &current_number);
        if (i==0) {
            continue;
        }
        if (current_number == previous_number+1) {
            current_interval_length ++;
        }
        else {
            current_interval_length = 1;
        }
        if (current_interval_length > max_interval_length) {
            max_interval_length = current_interval_length;
        }
    }
    printf("%u", max_interval_length);
    return 0;
}
