#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int y, m, d; } Date;

int is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int days_in_month(int y, int m) {
    int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m < 1 || m > 12) return 0;
    if (m == 2 && is_leap(y)) return 29;
    return days[m];
}

int is_valid_date(Date x) {
    return x.y >= 1 && x.y <= 9999 && x.m >= 1 && x.m <= 12
        && x.d >= 1 && x.d <= days_in_month(x.y, x.m);
}

int day_of_year(Date x) {
    int result = x.d;
    for (int m = 1; m < x.m; m++) result += days_in_month(x.y, m);
    return result;
}

Date next_day(Date x) {
    x.d++;
    if (x.d > days_in_month(x.y, x.m)) {
        x.d = 1;
        x.m++;
        if (x.m > 12) { x.m = 1; x.y++; }
    }
    return x;
}

int date_to_days(Date x) {
    int y = x.y - 1;
    return y * 365 + y / 4 - y / 100 + y / 400 + day_of_year(x) - 1;
}

int date_diff(Date a, Date b) {
    return abs(date_to_days(a) - date_to_days(b));
}

Date days_to_date(int serial) {
    int l=1,r=9999;
    while(l<r) {
        int m=l+(r-l+1)/2;
        Date first={m,1,1};
        if(date_to_days(first)<=serial) l=m; else r=m-1;
    }
    Date x={l,1,1};
    int remaining=serial-date_to_days(x);
    while(remaining>=days_in_month(x.y,x.m)) { remaining-=days_in_month(x.y,x.m); x.m++; }
    x.d=remaining+1;
    return x;
}
Date add_days(Date x,int delta) { return days_to_date(date_to_days(x)+delta); }

int main(void) {
    Date start = {
        .y = 2025,
        .m = 12,
        .d = 5,
    };
    int n;
    scanf("%d", &n);
    Date result = add_days(start, n);
    printf("%04d-%02d-%02d", result.y, result.m, result.d);

    return 0;
}
