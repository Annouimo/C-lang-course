#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum{
    LOVE_LIST_LIMIT = 100010,
};

struct love_item{
    size_t index;
    uint64_t score;
};

int compare(const void * a, const void * b){
    uint64_t a_value = (*((struct love_item *)a)).score;
    uint64_t b_value = (*((struct love_item *)b)).score;
    if (a_value > b_value) {
        return 1;
    }
    else if (a_value < b_value) {
        return -1;
    }
    else {
        return 0;
    }
};

int main(void){
    struct love_item love_list[LOVE_LIST_LIMIT];
    size_t n;
    uint64_t P;
    scanf("%zu%llu", &n, &P);

    for (size_t i = 0; i < n; i++) {
        scanf("%llu", &(love_list[i].score));
        love_list[i].index = i+1;
    }

    qsort(love_list, n, sizeof(struct love_item), compare);

    for (size_t i = 0; i < n; i++) {
        printf("%zu ", love_list[n-i-1].index);
    }
    return 0;
}
