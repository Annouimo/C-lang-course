#include <stdio.h>

int gcd(int a,int b);
void order(int *a, int *b);

int main(void){
    int a,b;
    scanf("%d%d", &a, &b);
    order(&a, &b);
    printf("%d", gcd(a, b));
    printf("\n");
    return 0;
}

int gcd(int a,int b) // a>b
{
    if (b==0) {
        return a;
    }
    if (a%b==0) {
        return b;
    }
    return gcd(b, a%b);
}

void order(int *a, int *b){
    if (a<b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}
