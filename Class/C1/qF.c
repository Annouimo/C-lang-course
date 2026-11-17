#include <stdio.h>

int main(){
    int a,b;
    scanf("%d%d", &a, &b);
    if (b != 0)
    {
        printf("%d / %d = %d", a, b, a/b);
    }
    else 
    {
        printf("Error!");
    }
    return 0;
}