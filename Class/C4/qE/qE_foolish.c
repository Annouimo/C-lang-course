#include <stdio.h>
#include <stdbool.h>

void print_range(unsigned int start, unsigned int count);


int main(void){
    unsigned int x, sum_case = 0;
    scanf("%u", &x);
    for (int i = 1; i<=(x/2+1); i++) {
        for (int j = i+1; j<=(x/2+1); j++) {
            //printf("****%u %u %u****\n", i, j, ((i+j)*(j-i+1)/2));
            if (((i+j)*(j-i+1)/2)==x) {

                printf("%d = ", x);
                print_range(i, j-i+1);
                printf("\n");
                sum_case++;
            }
        }
    }
    printf("cases: %u", sum_case);
}

void print_range(unsigned int start, unsigned int count){
    bool is_first_turn = true;
    for (unsigned int i = 0; i<count; i++) {
        if (is_first_turn) {
            is_first_turn = false;
        }
        else {
            printf("+");
        }
        printf("%d", start+i);
    }
}
