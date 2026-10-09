#include <stdio.h>
#include <limits.h>
#include <float.h>

void print_limits(void);

int main(void){
    printf("%x\n", (short)(-255));
    return 0;
}

void print_limits(void){
    printf("Int max: %d, min: %d\n", INT_MAX, INT_MIN);
    printf("Double max: %lf, min %lf\n", DBL_MAX, DBL_MIN);
}
