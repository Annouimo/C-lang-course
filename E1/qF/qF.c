#include <stdio.h>

int printchar(char str, int n, int start, int end){
    for (size_t i = 1; i <= n; i++)
    {
        if (i>=start && i<=end)
        {
            printf("%c", str);
        }
        else{
            printf(" ");
        }
        
    }
    printf(" ");
    
}

int main(){
    int n=0;
    scanf("%d", &n);
    for (size_t i = 1; i <= n; i++)
    {
        if (i==1 || i==n)
        {
            printchar('E', n, 1, n); printchar('Z', n, 1, n);
        }
        else if (i==(n+1)/2)
        {
            printchar('E', n, 1, n); printchar('Z', n, n-i+1, n-i+1);
        }
        else
        {
            printchar('E', n, 1, 1); printchar('Z', n, n-i+1, n-i+1);
        }
        printf("\n");
    }
    
    return 0;
    
}