#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_euqal(double a, double b);

int main(void){
    int n;
    double a, b, plus;
    scanf("%d", &n);
    for (size_t i = 0; i<n; i++) {
        scanf("%lf%lf%lf", &a, &b, &plus);
        if (is_euqal(a+b, plus)) {
            printf("Accepted");
        }
        else {
            printf("Wrong Answer");
        }
        printf("\n");
    }
    return 0;
}

bool is_euqal(double a, double b){
    if (fabs(a-b)<1e-9) {
        return true;
    }
    else {
        return false;
    }
}
