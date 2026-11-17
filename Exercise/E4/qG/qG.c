#include <stddef.h>
#include <stdio.h>
#include <stdnoreturn.h>

enum {
    MAX_CAPACITY = 10000,
};

struct candy_box {
    unsigned int capacity[MAX_CAPACITY];
    unsigned int used[MAX_CAPACITY];
};
typedef void (*candy_operate)(struct candy_box *, unsigned int) ;
typedef void (*candy_operate_3)(struct candy_box *, unsigned int, unsigned int) ;

void candy_print(struct candy_box *box, unsigned int index);
void candy_clear(struct candy_box *box, unsigned int index);
void candy_fill(struct candy_box *box, unsigned int index);
void candy_set(struct candy_box *box, unsigned int index);
void candy_swap(struct candy_box *box, unsigned int index, unsigned int other_index);
void candy_adjust(struct candy_box *box, unsigned int index);
void candy_transfer(struct candy_box *box, unsigned int index, unsigned int other_index);

static const candy_operate operation_table[8] = {0, candy_print, candy_clear, candy_fill, candy_set, 0,candy_adjust};
static const candy_operate_3 operation_table_3[8] = {0,0,0,0,0, candy_swap,0,candy_transfer};
void candy_operation(struct candy_box *box);
void candy_initialize(struct candy_box *box, unsigned int n);
void candy_print_status(struct candy_box *box, unsigned int n);

static unsigned int clamp_invalid(int value, unsigned int max);

int main(void){
    struct candy_box box = {.capacity = {0},.used = {0}};
    unsigned int n=0u, m=0u;
    scanf("%u%u", &n, &m);
    candy_initialize(&box, n);
    for (size_t i = 0; i<m; i++) {
        candy_operation(&box);
    }
    candy_print_status(&box, n);
    return 0;
}

void candy_operation(struct candy_box *box){
    unsigned int operation = 0;
    scanf("%u", &operation);
    if (operation == 5 || operation == 7) {
        unsigned int start_index = 0, other_start_index = 0, count = 0;
        scanf("%u%u%u", &start_index, &other_start_index, &count);
        for (size_t i = 0; i < count; i++) {
            operation_table_3[operation](box, i+start_index, i+other_start_index);
        }
    }
    else {
        unsigned int start_index = 0, count = 0;
        scanf("%u%u", &start_index, &count);
        for (size_t i = start_index; i < start_index + count; i++) {
            operation_table[operation](box, i);
        }
        if (operation == 1) {
            printf("\n");
        }
    }

}
void candy_initialize(struct candy_box *box, unsigned int n){
    for (size_t i = 0; i<n; i++) {
        scanf("%u", &(box->capacity[i]));
    }
    for (size_t i = 0; i<n; i++) {
        scanf("%u", &(box->used[i]));
    }
}
void candy_print_status(struct candy_box *box, unsigned int n){
    for (size_t i = 0; i<n; i++) {
        candy_print(box, i);
    }
}

void candy_print(struct candy_box *box, unsigned int index){
    printf("%u ", box -> used[index]);
}
void candy_clear(struct candy_box *box, unsigned int index){
    box -> used[index] = 0;
}
void candy_fill(struct candy_box *box, unsigned int index){
    box -> used[index] = box -> capacity[index];
}
void candy_set(struct candy_box *box, unsigned int index){
    unsigned int value = 0;
    scanf("%u", &value);
    box -> used[index] = value;
}
void candy_swap(struct candy_box *box, unsigned int index, unsigned int other_index){
    unsigned int result = clamp_invalid(box -> used[other_index], box -> capacity[index]);
    unsigned int other_result = clamp_invalid(box -> used[index], box -> capacity[other_index]);
    box -> used[index] = result;
    box -> used[other_index] = other_result;
}
void candy_adjust(struct candy_box *box, unsigned int index){
    int value = 0;
    scanf("%d", &value);
    box -> used[index] = clamp_invalid((int)(box -> used[index]) + value, box -> capacity[index]);
}
void candy_transfer(struct candy_box *box, unsigned int index, unsigned int other_index){
    unsigned int sum = box -> used[index] + box -> used[other_index];
    if (sum > box -> capacity[other_index]) {
        box -> used[other_index] = box -> capacity[other_index];
        box -> used[index] = sum - box -> capacity[other_index];
    }
    else {
        box -> used[other_index] = sum;
        box->used[index] = 0;
    }
}

static unsigned int clamp_invalid(int value, unsigned int max){
    if (value <= 0) {
        return 0u;
    }
    else if (value >= max) {
        return max;
    }
    else {
        return value;
    }
}
