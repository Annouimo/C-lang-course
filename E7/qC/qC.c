#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

enum{
    ARRAY_SIZE_LIMIT = 1010,
};

void range_turn(int32_t * p, int32_t * q, int32_t * r);

int main(void){
    size_t n,m;
    scanf("%zu%zu", &n, &m);
    int32_t a[ARRAY_SIZE_LIMIT];
    for (size_t i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    size_t p,q,r;
    for (size_t i = 0; i < m; i++) {
        scanf("%zu%zu%zu", &p, &q, &r);
        range_turn(&a[p], &a[q], &a[r]);
    }
    for (size_t i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

void range_turn(int32_t * p, int32_t * q, int32_t * r){
    int32_t p_origin = *p, q_origin = *q, r_origin = *r;
    *q = p_origin;
    *r = q_origin;
    *p = r_origin;
}
