#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

enum{
    HEIGHT_COUNT_LIMIT = 1005,
};

int compare(const void * a, const void * b){
    return (int)(*(unsigned int *)a - *(unsigned int *)b);
}
size_t linear_to_maxmin_range(size_t i, size_t n);

int main(void){
    size_t n;
    scanf("%zu", &n);
    unsigned int height[HEIGHT_COUNT_LIMIT];
    for (size_t i = 0; i < n; i++) {
        scanf("%u", &height[i]);
    }
    qsort(height, n, sizeof(unsigned int), compare);

    size_t index;
    for (size_t i = 0; i < n; i++) {
        index = linear_to_maxmin_range(i, n);
        printf("%u ", height[index]);
    }
    return 0;
}

size_t linear_to_maxmin_range(size_t i, size_t n){
    if (i % 2 == 0) {
        return n - i/2 - 1;
    }
    else {
        return i/2;
    }
}
