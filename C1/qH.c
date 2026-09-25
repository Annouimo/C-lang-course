#include <stdio.h>

int main(){
    int p, a, sum;
    scanf("%d", &p);
    sum = 0;
    a = 0;
    while (1)
    {
        scanf("%d", &a);
        if (a==-1)
        {
            break;
        }
        sum = sum + a;
    }
    printf("%d", sum/p);
}