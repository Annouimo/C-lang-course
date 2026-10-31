#include <stddef.h>
#include <stdio.h>

enum{
    MAX_VALUE = 200005,
};

void update_max(unsigned int this, unsigned int *max);

int main(void){
    unsigned int n;
    scanf("%u", &n);

    unsigned int count_each_value[MAX_VALUE] = {};
    unsigned int current_value;
    unsigned int max_count_value = 0;
    for (size_t i = 0; i < n; i++) {
        scanf("%u", &current_value);
        count_each_value[current_value]++;
        update_max(count_each_value[current_value], &max_count_value);
    }
    printf("%u", max_count_value);
    return 0;
}

void update_max(unsigned int this, unsigned int *max){
    if (this>=*max) {
        *max = this;
    }
}
