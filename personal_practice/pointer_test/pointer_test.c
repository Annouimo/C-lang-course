#include <stdio.h>

void decompose(int *a, int *b);

int main() {
    int a = 10, b = 20;
    int *p;
    printf("Before decomposition: a = %d, b = %d\n", a, b);
    decompose(&a, &b);
    printf("After decomposition: a = %d, b = %d\n", a, b);
    return 0;
}

void decompose(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
