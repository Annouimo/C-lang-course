#include <stdio.h>
#include <stdbool.h>

long long int f(long long int, long long int);
bool find_resolution(long long int x, long long int *flag);

int main()
{
    long long int n, y = 2, sum = 1;
    scanf("%lld", &n);
    // printf("find?: %d, final = %lld", find_resolution(3,&upper), upper);
    if (n==1)
    {
        printf("0");
        return 0;
    }
    
    for (long long int x = 2; y < n; x++)
    {   
        sum += find_resolution(x, &y);
        // printf("sum = %lld, find (%lld, %lld)\n", sum, x, y);
        
    }
    printf("%lld", sum);
    return 0;
}

long long int f(long long int x, long long int y)
{
    return x * x + y * y + 1 - 3 * x * y;
}

bool find_resolution(long long int x, long long int *flag)
{
    long long int f_start = f(x, *flag);
    long long int fx = 0;
    for (; (fx = f(x, *flag)) * f_start > 0; (*flag)++)
    {
    }
    // printf("f(x) = %d, find (%d,%d)", f(x,flag), x, flag);
    if (fx == 0)
    {   
        return true;
    }
    else
    {
        (*flag)--;
        return false;
    }
}