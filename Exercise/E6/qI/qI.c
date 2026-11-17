#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

enum{
    STRING_LENGTH_LIMIT = 105,
    TIME_TABLE_LIMIT = 2005,
};

uint32_t construct_time_number(uint32_t hour, uint32_t minute);
bool get_time_table(uint32_t time_table[], size_t *time_table_size);
uint32_t find_time_table(uint32_t time_table[], uint32_t index, uint32_t now, uint32_t time_table_size);

int main(void){
    char line_name[STRING_LENGTH_LIMIT];
    fgets(line_name, STRING_LENGTH_LIMIT, stdin);
    printf("%s", line_name);
    char terminal_station[STRING_LENGTH_LIMIT];
    scanf(" Train terminate in %s station", terminal_station);
    printf("%s\n", terminal_station);

    uint32_t time_table[TIME_TABLE_LIMIT];
    size_t time_table_size = 0;
    while (get_time_table(time_table, &time_table_size)) {;}

    uint32_t hour, minute, now;
    uint32_t index=0;
    while (scanf("%u:%u", &hour, &minute)!=EOF) {
        index = 0;
        printf("%.2u:%.2u\n", hour, minute);
        now = construct_time_number(hour, minute);
        printf("This Train: ");
        index = find_time_table(time_table, index, now, time_table_size);
        printf("\n");
        printf("Next Train: ");
        find_time_table(time_table, index+1, now, time_table_size);
        printf("\n");
    }
}

uint32_t construct_time_number(uint32_t hour, uint32_t minute){
    return hour * 60 + minute;
}

bool get_time_table(uint32_t time_table[], size_t *time_table_size){
    uint32_t hour=0, minute=0;
    scanf("%u", &hour);
    if (hour == -1) {
        return false;
    }
    while (true) {
        scanf("%u", &minute);
        if (minute == -1) {
            return true;
        }
        time_table[*time_table_size] = construct_time_number(hour, minute);
        (*time_table_size) ++;
    }
}

uint32_t find_time_table(uint32_t time_table[], uint32_t index, uint32_t now, uint32_t time_table_size){
    while (index < time_table_size && time_table[index] < now) {
        (index) ++;
    }
    if (index >= time_table_size) {
        ;
    }
    else if (time_table[index] == now) {
        printf("Arrived");
    }
    else {
        printf("%u min", time_table[index]-now);
    }
    return index;
}
