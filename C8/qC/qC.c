#include <stddef.h>
#include <stdio.h>
#include <math.h>

long long stage(long long n){
    long long result=1;
    for (size_t i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void){
    double lambda;
    long long k;
    scanf("%lf%lld", &lambda, &k);

    double result = exp(-lambda)*pow(lambda, (double)k)/stage(k);
    printf("%.6lf", result);
    return 0;
}
