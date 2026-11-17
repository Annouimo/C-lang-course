#include <stdio.h>

int main(void)
{
    long long n, sum = 0;
    while (sum <= 2147483647)
    {
        scanf("%lld", &n);
        sum += n;
    }
    printf("%lld", sum - n);
    return 0;
}