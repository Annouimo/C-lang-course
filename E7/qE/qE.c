#include <stdio.h>

unsigned int digit_sum(unsigned int number){
    unsigned int sum = 0;
    while (number != 0) {
        sum += number%10;
        number /= 10;
    }
    return sum;
}

int cmp(const void *p1, const void *p2) {
    unsigned int p1_value = digit_sum(*(unsigned int *)p1);
    unsigned int p2_value = digit_sum(*(unsigned int *)p2);
    if  (p1_value > p2_value) {
        return 1;
    }
    else if (p1_value < p2_value) {
        return -1;
    }
    else {
        return 0;
    }
}

// int main() {
// }

#include <stdio.h>
#include <stdlib.h>

unsigned int oj_a[200005];

int cmp(const void *p1, const void *p2);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%u", &oj_a[i]);
    qsort(oj_a, n, sizeof(unsigned int), cmp);
    for (int i = 0; i < n; i++)
        printf("%u%c", oj_a[i], i + 1 < n ? ' ' : '\n');
    return 0;
}
