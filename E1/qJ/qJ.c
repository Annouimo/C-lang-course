#include <stdio.h>

int main()
{
    long long int t, n, x, a, big, small, bigger, smaller, equal;
    scanf("%lld", &t);
    for (size_t i = 0; i < t; i++)
    {
        scanf("%lld%lld", &n, &x);
        big = 0;
        small = 0;
        equal = 0;
        bigger = 2000000000;
        smaller = -2000000000;
        for (size_t j = 0; j < n; j++)
        {
            scanf("%lld", &a);
            if (a >= x)
            {
                big++;
                if ((bigger - x) > (a - x))
                {
                    bigger = a;
                }
            }
            if (a <= x)
            {
                small++;
                if ((x - smaller) > (x - a))
                {
                    smaller = a;
                }
            }
            if (a == x)
            {
                equal++;
            }
        }
        if ((n % 2 == 0)&&(equal==0))
        {
            if ((big == small) && (bigger - x == x - smaller))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            if (((big - small < equal) && (big - small > equal * (-1))) && (bigger - x == x - smaller))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
}