#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int longest_run(int a[], int n, int consecutive) {
    if (n == 0) return 0;
    int length = 1, best = 1;
    bool is_have_zero = false;
    if (a[0]==0) {
        is_have_zero = true;
    }
    for (int i = 1; i < n; i++) {
        if (a[i]==0) {
            is_have_zero = true;
        }
        int ok = consecutive ? (a[i] > a[i-1] && (unsigned long long)a[i] - (unsigned long long)a[i-1] == 1) : (a[i] == a[i-1]&&a[i]==0);
        length = ok ? length+1 : 1;
        if (length > best) best = length;
    }
    if (!is_have_zero) {
        return 0;
    }
    return best;
}

int main(void) {
    int tests;
    if (scanf("%d", &tests) != 1) return 0;
    while (tests--) {
        size_t size;
        int result[110];
        scanf("%zu", &size);
        for (size_t i = 0; i < size; i++) {
            scanf("%d", &(result[i]));
        }
        printf("%d\n", longest_run(result, size, 0));

    }
    return 0;
}
