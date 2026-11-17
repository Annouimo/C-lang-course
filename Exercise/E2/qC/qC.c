#include <stdio.h>
#include <math.h>

double distance(double , double, double, double);

int main(void)
{
    int n;
    double x0, y0, x1, y1;
    scanf("%lf%lf%d", &x0, &y0, &n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lf%lf", &x1, &y1);
        printf("%.3lf\n", distance(x0, y0, x1, y1));
    }
    return 0;
}

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}