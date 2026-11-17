#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

enum{
    FISH_COUNT_LENGTH = 1000005,
};

struct Range {
    long long int start;
    long long int end;
};

bool is_range_include(struct Range inner_range, struct Range outer_range);
struct Range range_intersection(struct Range range_1, struct Range range_2);
unsigned long long int sum_array_range(
    unsigned long long int array[], struct Range range);

int main(void){
    long long int n,k,L;
    char direction;
    scanf("%lld%lld%lld %c", &n, &k, &L, &direction);
    struct Range explode_range;
    if (direction == 'L') {
        explode_range.start = k-L;
        explode_range.end = k;
    }
    else if (direction == 'R') {
        explode_range.start = k+1;
        explode_range.end = k+L+1;
    }

    unsigned long long int fish_count[FISH_COUNT_LENGTH];
    for (size_t i = 1; i <= n; i++) {
        scanf("%llu", &fish_count[i]);
    }

    struct Range pool_range = {
        .start = 1,
        .end = n+1,
    };
    printf("%llu\n", sum_array_range(
        fish_count,
        range_intersection(pool_range, explode_range)
    ));
    if (is_range_include(explode_range, pool_range)) {
        printf("(^o^)");
    }
    else {
        printf("(ToT)");
    }

}

bool is_range_include(struct Range inner_range, struct Range outer_range){
    if (
        inner_range.start >= outer_range.start &&
        inner_range.end <= outer_range.end
    ) {
        return true;
    }
    else {
        return false;
    }
}

struct Range range_intersection(struct Range range_1, struct Range range_2){
    struct Range intersection = {
        .start = range_1.start >= range_2.start ? range_1.start : range_2.start,
        .end = range_1.end <= range_2.end ? range_1.end : range_2.end,
    };
    return intersection;
}

unsigned long long int sum_array_range(
    unsigned long long int array[], struct Range range
){
    unsigned long long int sum = 0;
    for (size_t i = range.start; i < range.end; i++) {
        sum += array[i];
    }
    return sum;
}
