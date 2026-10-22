#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdnoreturn.h>

struct Date{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

bool is_leap_year(unsigned int year);
unsigned int days_of_month(struct Date date);
struct Date get_next_anniversary(struct Date this_anniversary);

int main(void){
    struct Date date;
    unsigned int T = 0;
    scanf("%u", &T);
    for (size_t i = 0; i<T; i++) {
        scanf("%u%u%u", &date.year, &date.month, &date.day);
        unsigned int k=0;
        scanf("%u", &k);
        for (size_t j = 0; j<k; j++) {
            date = get_next_anniversary(date);
        }
        printf("%u %u %u\n", date.year, date.month, date.day);
    }
}

bool is_leap_year(unsigned int year){
    if ((year%4==0)&&((year%100!=0)||(year%400==0))) {
        return true;
    }
    else {
        return false;
    }
}

unsigned int days_of_month(struct Date date){
    if (date.month==2) {
        if (is_leap_year(date.year)) {
            return 29u;
        }
        else {
            return 28u;
        }
    }
    else {
        unsigned int days_month_map[13] = {0,
            31,0 ,31,30,31,30,
            31,31,30,31,30,31
        };
        return days_month_map[date.month];
    }
}

struct Date get_next_anniversary(struct Date this_anniversary){
    struct Date next_anniversary = this_anniversary;
    next_anniversary.month++;
    if (next_anniversary.month>=13) {
        next_anniversary.year++;
        next_anniversary.month = 1;
    }
    unsigned int next_month_days = days_of_month(next_anniversary);
    //printf("******%u %u\n", next_month_days, this_anniversary.month);
    if (next_anniversary.day<=next_month_days) {
        return next_anniversary;
    }
    else {
        return get_next_anniversary(next_anniversary);
    }
}
