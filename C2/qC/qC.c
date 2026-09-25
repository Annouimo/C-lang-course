#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (a == 0)
    {
        if (b == 0)
        {
            if (c != 0){
                printf("N0 real root");
            }
            else printf("1nfinite solutions");
        }
        else
        {
            printf("%.3lf", (-1.0) * c / b);
        }
        return 0;
    }

    double delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        printf("N0 real root");
        return 0;
    }
    else {
        double x1 = (-b+sqrt(delta))/(2*a);
        double x2 = (-b-sqrt(delta))/(2*a);
        if (x1<x2){
            printf("%.3lf %.3lf", x1, x2);
        }
        else if (x1>x2){
            printf("%.3lf %.3lf", x2, x1);
        }
        else{
            printf("%.3lf", x1);
        }
        
    }
}