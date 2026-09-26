#include <stdio.h>

void YMDtoJDN(int, int, int, int *);
void JDMtoYMD(int, int *, int *, int *);

int main()
{
    int Y, M, D, JDN;
    int p, q;
    scanf("%d%d", &p, &q);
    for (size_t i = 0; i < p; i++)
    {
        scanf("%d%d%d", &Y, &M, &D);
        YMDtoJDN(Y, M, D, &JDN);
        printf("%d\n", JDN);
    }
    for (size_t i = 0; i < q; i++)
    {
        scanf("%d", &JDN);
        JDMtoYMD(JDN, &Y, &M, &D);
        printf("%04d %02d %02d\n", Y, M, D);
    }

    return 0;
}

void YMDtoJDN(int Y, int M, int D, int *JDN)
{
    int a, y, m;
    a = (14 - M) / 12;
    y = Y + 4800 - a;
    m = M + 12 * a - 3;
    *JDN = D + (153 * m + 2) / 5 + 365 * y + y / 4 + -y / 100 + y / 400 - 32045;
}

void JDMtoYMD(int JDN, int *Y, int *M, int *D)
{
    int a, b, c, d, e, m;
    a = JDN + 32044;
    b = (4 * a + 3) / 146097;
    c = a - (146097 * b) / 4;
    d = (4 * c + 3) / 1461;
    e = c - (1461 * d) / 4;
    m = (5 * e + 2) / 153;
    *D = e - (153 * m + 2) / 5 + 1;
    *M = m + 3 - 12 * (m / 10);
    *Y = 100 * b + d - 4800 + (m / 10);
}