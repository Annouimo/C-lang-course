#include <stdio.h>

/* ===== 只补全 days_in_year 的函数体，不要改动 main ===== */
int days_in_year(int year)
{
    return 365+((year%4==0)&&((year%100!=0)||(year%400==0)));
}

int main()
{
    int y;
    scanf("%d", &y);
    printf("%d\n", days_in_year(y));
    return 0;
}
