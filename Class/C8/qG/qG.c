#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id, score;
} Record;

int cmp_record(const void *a, const void *b) {
    Record x = *(const Record *)a, y = *(const Record *)b;
    if (x.score > y.score) return -1;
    if (x.score < y.score) return 1;
    if (x.id < y.id) return -1;
    if (x.id > y.id) return 1;
    return 0;
}

int main(void) {
    int tests;
    if (scanf("%d", &tests) != 1) return 0;
    Record count[30];
    for (size_t i = 0; i < 30; i++) {
        count[i].id = i;
        count[i].score = 0;
    }
    while (tests--) {
        bool is_occur[30] = {0};
        while (1) {
            char ch = ' ';
            scanf("%c", &ch);
            if (ch == '\n') {
                break;
            }
            int char_num = ch - 'a';
            if (!is_occur[char_num]) {
                is_occur[char_num] = true;
            }
        }
        if(is_occur['l'-'a']) for (size_t i = 0; i < 26; i++) {
            if (is_occur[i]) {
                count[i].score++;
            }
        }
    }
    if (count['l'-'a'].score==0) {
        printf("-1");
        return 0;
    }
    count['l'-'a'].score = 0;
    qsort(count, 26, sizeof(count[0]), cmp_record);
    if (count[0].score == 0) {
        printf("-1");
        return 0;
    }
    printf("%c %d", count[0].id + 'a', count[0].score);
    return 0;
}
