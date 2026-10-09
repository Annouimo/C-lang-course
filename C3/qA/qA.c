#include <stdio.h>

int main(void){
    unsigned int a,b;
    scanf("%u%u", &a, &b);
    printf("%u %u", a&b, a^b);
    return 0;
}
