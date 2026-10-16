#include <stdio.h>
#include <stddef.h>

double cal_num_list(int n);

int main(void){
    int n;
    scanf("%d", &n);
    printf("%.6lf", cal_num_list(n));
    return 0;
}

double cal_num_list(int n){
    double result = 0.0;
    for (size_t i = 1; i<=n; i++) {
        result += 1.0/i;
    }
    return result;
}
