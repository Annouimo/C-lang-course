#include <stdio.h>
#include <math.h>
static const double eps = 1e-6;

int main()
{
    double l, r;

    // 判断l, r是否相等
    if (fabs(l - r) < eps)

        // 判断l是否大于r
        if (l > r + eps)

            // 判断l是否小于r
            if (l < r - eps)
            {
            }

    int t;
    double a, b, c, delta;
    scanf("%d", &t);
    for (size_t i = 0; i < t; i++)
    {
        scanf("%lf%lf%lf", &a, &b, &c);
        delta = pow(a, 2) + pow(b, 2) - pow(c, 2);
        if (a + b < c + eps)
        {
            printf("No Triangle");
        }
        else if (delta > eps)
        {
            printf("Acute Triangle");
        }
        else if (delta < -eps)
        {
            printf("Obtuse Triangle");
        }
        else
        {
            printf("Right-angled Triangle");
        }
        printf("\n");
    }

    return 0;
}