#include <stdio.h>

int count_ones(unsigned long long int value);

int main(void){
    int n;
    unsigned long long int a;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        scanf("%llu", &a);
        printf("%d ", count_ones(a));
    }
    return 0;
}

int count_ones(unsigned long long int value){
    int count = 0;
    while (value != 0) {
        count += value % 2;
        value /= 2;
    }
    return count;
}
