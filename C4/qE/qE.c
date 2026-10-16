#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

bool print_solution(unsigned int double_centre, unsigned int count, unsigned int origin_number);
void print_range(unsigned int start, unsigned int count);

int main(void){
    unsigned int x, sum_case = 0;
    bool flag;
    scanf("%u", &x);
    x = x*2;
    for (size_t i = 0; i*i<x; i++) {
        if (x%i == 0) {
            sum_case += print_solution(i, x/i, x/2);
        }
    }
    printf("%u", sum_case);
    return 0;
}

bool print_solution(unsigned int double_centre, unsigned int count, unsigned int origin_number){
    unsigned int start;
    if((double_centre%2 == 0)&&(count%2 == 1)){
        start = double_centre/2-(count-1)/2;
        printf("\n****%d****", start);
        if (start<=0) {
            return false;
        }
        printf("%d = ", origin_number);
        print_range(start, count);
        printf("\n");
        return true;
    }
    else if ((double_centre%2 == 1)&&(count%2 == 0)) {
        start = (double_centre-1)/2-count/2+1;
        if (start<=0) {
            return false;
        }
        printf("%d = ", origin_number);
        print_range(start, count);
        printf("\n");
        return true;
    }
    return false;
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
