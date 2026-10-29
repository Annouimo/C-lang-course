#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

enum{
    MAX_N = 1000,
};

void bubble_sort(unsigned int array[], size_t size);
void exchange(unsigned int* a, unsigned int * b);

int main(void){
    unsigned int d[MAX_N]={0};
    unsigned int n=0;
    scanf("%u", &n);
    for (size_t i = 0; i < n; i++) {
        scanf("%u", &d[i]);
    }
    bubble_sort(d, n);
    for (size_t i = 0; i < n; i++) {
        printf("%u ", d[i]);
    }
}

void bubble_sort(unsigned int array[], size_t size){
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size-1; j++) {
            if (array[j]>array[j+1]) {
                exchange(&array[j], &array[j+1]);
            }
        }
    }
}

void exchange(unsigned int * a, unsigned int * b){
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}
