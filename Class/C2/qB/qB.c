#include <stdio.h>

int digit(long long num){
    long long int output = 0;
    while(num>0){
        num /= 10;
        output ++;
    }
    return output;
}

void print_enhanced(char begin,long long int n, long long int num){
    printf("%c ", begin);
    for (size_t i = 0; i < n-digit(num); i++)
    {
        printf(" ");
    }
    printf("%lld\n", num);
}

int main(){
    long long int a, b;
    scanf("%lld%lld", &a, &b);
    
    int n = digit(a+b);
    print_enhanced(' ', n, a);
    print_enhanced('+', n, b);
    for (size_t i = 0; i < n+2; i++)
    {
        printf("-");
    }
    if (n==0)
    {
        printf("-");
    }
    
    printf("\n");
    print_enhanced(' ', n, a+b);
}