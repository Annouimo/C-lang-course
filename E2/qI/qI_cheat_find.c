#include <stdio.h>
#include <stdbool.h>

__int128_t f(__int128_t, __int128_t);
bool find_resolution(__int128_t x, __int128_t *flag);

int sum_N=0;

int main()
{
    __int128_t n=11000000000, y = 2, sum = 1;
    // printf("find?: %d, final = %lld", find_resolution(3,&upper), upper);
    if (n==1)
    {
        printf("0");
        return 0;
    }
    
    for (__int128_t x = 2; y < n; x++)
    {   
        sum += find_resolution(x, &y);
        // printf("sum = %lld, find (%lld, %lld)\n", sum, x, y);
        
    }
    return 0;
}

__int128_t f(__int128_t x, __int128_t y)
{
    return x * x + y * y + 1 - 3 * x * y;
}

bool find_resolution(__int128_t x, __int128_t *flag)
{
    __int128_t f_start = f(x, *flag);
    __int128_t fx = 0;
    for (; (fx = f(x, *flag)) * f_start > 0; (*flag)++)
    {
    }
    // printf("f(x) = %d, find (%d,%d)", f(x,flag), x, flag);
    if (fx == 0)
    {
        printf("%lld, ", (long long int)*flag);
        sum_N ++;
        if (sum_N%30==0)
        {
            printf("\n");
        }
        
        return true;
    }
    else
    {
        (*flag)--;
        return false;
    }
}