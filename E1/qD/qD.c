#include <stdio.h>

int main()
{
    long long int T, a, b;
    scanf("%lld", &T);
    for (size_t i = 0; i < T; i++)
    {
        scanf("%lld%lld", &a, &b);
        if (a > b)
        {
            printf("%lld\n", a - b);
        }
        else
        {
            printf("%lld\n", b - a);
        }
    }
    return 0;
}