#include <stdio.h>

int main(){
    int a,b,min;
    scanf("%d%d", &a, &b);
    if (a<b)
    {
        min = a;
    }
    else{
        min = b;
    }

    if (a==0)
    {
        printf("%d", b);
    }
    else if (b==0)
    {
        printf("%d", a);
    }
    
    
    for (size_t i = min; i > 0; i--)
    {
        if (a%i==0 && b%i==0)
        {
            printf("%d", i);
            return 0;
        }
        
    }
}