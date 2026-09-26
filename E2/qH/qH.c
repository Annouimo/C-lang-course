#include <stdio.h>
#include <math.h>

long long int find_j(long long int);

int main(void)
{
    int T,j;
    long long int N;
    scanf("%d", &T);
    for (size_t i = 0; i < T; i++)
    {
        scanf("%lld", &N);
        printf("%lld\n", find_j(N));
    }
    
}

long long int find_j(long long int N)
{
    long long int j=sqrt((double)(N*2))-1;
    for (; !(0<=(N*2-j*j+j)&&(N*2-j*j+j)<=(2*j-2)); j++){}
    return j-1;
}
