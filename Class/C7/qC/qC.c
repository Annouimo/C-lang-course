#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct TuringMachine {
    int64_t * tape;
    int64_t * head;
};

struct TuringMachine TMInitialize(size_t head_initial, size_t tape_length);
void TMLeft(struct TuringMachine * machine ,size_t k);
void TMRight(struct TuringMachine * machine ,size_t k);
void TMChange(struct TuringMachine * machine , int64_t x);
int64_t TMRead(struct TuringMachine * machine);

int main(void){
    size_t n, q, p;
    scanf("%zu%zu%zu", &n, &q, &p);
    struct TuringMachine machine = TMInitialize(p, n+10);
    for (size_t i = 1; i <= n; i++) {
        scanf("%llu", &machine.tape[i]);
    }

    char operation;
    size_t op_index;
    int64_t op_number;
    for (size_t i = 0; i < q; i++) {
        scanf(" %c", &operation);
        switch (operation) {
            case 'L':
                scanf("%zu", &op_index);
                TMLeft(&machine, op_index);
                break;
            case 'R':
                scanf("%zu", &op_index);
                TMRight(&machine, op_index);
                break;
            case 'C':
                scanf("%lld", &op_number);
                TMChange(&machine, op_number);
                break;
            case 'Q':
                printf("%lld\n", TMRead(&machine));
                break;
        }
    }
    return 0;
}

struct TuringMachine TMInitialize(size_t head_initial, size_t tape_length){
    int64_t * tape_initial = malloc(tape_length * sizeof(int64_t));
    struct TuringMachine machine = {
        .tape = tape_initial,
        .head = tape_initial + head_initial,
    };
    return machine;
}

void TMLeft(struct TuringMachine * machine ,size_t k){
    machine->head -= k;
}

void TMRight(struct TuringMachine * machine ,size_t k){
    machine->head += k;
}

void TMChange(struct TuringMachine * machine , int64_t x){
    *(machine->head) = x;
}

int64_t TMRead(struct TuringMachine * machine){
    return *(machine->head);
}
