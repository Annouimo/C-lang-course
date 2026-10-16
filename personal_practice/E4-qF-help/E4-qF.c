#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

unsigned int month_calendar[13] = {0,31,0,31,30,31,30,31,31,30,31,30,31};

struct date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

struct date next_day(struct date today);
bool is_leap_year(unsigned int year);
void update_february(unsigned int year);

int main(void){
    unsigned int t,k;
    struct date today, result_day;
    scanf("%u", &t);
    for (size_t i = 0; i<t; i++) {
        scanf("%u%u%u%u", &today.year, &today.month, &today.day, &k);
        result_day = today;
        for (int j = 0; j<k; j++) {
            result_day = next_day(result_day);
        }
        printf("%u %u %u\n", result_day.year, result_day.month, result_day.day);
    }
}

struct date next_day(struct date today){
    struct date next_day = today;
    update_february(today.year);
    if ((today.day+1) <= (month_calendar[today.month]) ) {
        next_day.day++;
    }
    else if ((today.month+1)<=12) {
        next_day.month++;
        next_day.day = 1;
    }
    else {
        next_day.year++;
        next_day.month = 1;
        next_day.day = 1;
    }

    return next_day;
}

bool is_leap_year(unsigned int year){
    if(year%4 == 0){
        if (year%100 == 0) {
            if (year%400==0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

void update_february(unsigned int year){
    if (is_leap_year(year)) {
        month_calendar[2] = 29;
    }
    else {
        month_calendar[2] = 28;
    }
}
