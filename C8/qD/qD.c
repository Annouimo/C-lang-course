#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

void print_stage_result(int status[], int steps);
void find_former_method(int n, int method[], int steps, int *count);

int main(void) {
    int n;
    scanf("%d", &n);
    int method[50];
    int count = 0;
    find_former_method(n, method, 0, &count);
    printf("%d", count);
    return 0;
}

void find_former_method(int n, int method[], int steps, int *count){
    if (n == 0) {
        (*count)++;
        //print_stage_result(method, steps);
        return;
    }
    method[steps] = 1;
    find_former_method(n - 1, method, steps+1, count);
    if (n == 1) {
        return;
    }
    method[steps] = 2;
    find_former_method(n - 2, method, steps+1, count);
}

// void print_stage_result(int method[], int steps){
//     bool is_first_turn = true;
//     for (size_t i = 0; i < steps; i++) {
//         if (is_first_turn) {
//             is_first_turn = false;
//         }
//         else {
//             printf("+");
//         }
//         printf("%d", method[steps-i]);
//     }
//     printf("\n");
// }
