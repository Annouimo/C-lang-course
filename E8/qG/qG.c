#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
    QUESTION_COUNT_LIMIT = 20,
    TEAM_COUNT_LIMIT = 200010,
    TEAM_NAME_LENGTH_LIMIT = 20,
    RESULT_LEGTH_LIMIT = 10,
};

struct QuestionRecord{
    char id;
    int WA_count;
    bool is_AC;
    short int AC_time;
};

typedef struct {
    int id;
    char name[TEAM_NAME_LENGTH_LIMIT];
    int AC_count, punish;
    struct QuestionRecord question[QUESTION_COUNT_LIMIT];
} Record;

int cmp_record(const void *a, const void *b) {
    const Record * x = (const Record *)a, *y = (const Record *)b;
    if (x->AC_count > y->AC_count) return -1;
    if (x->AC_count < y->AC_count) return 1;
    if (x->punish > y->punish) return 1;
    if (x->punish < y->punish) return -1;
    int compare_result = strcmp(x->name, y->name);
    if (compare_result < 0) return -1;
    if (compare_result > 0) return 1;
    return 0;
}

static Record teams[TEAM_COUNT_LIMIT] = {0};

int main(void) {
    int n,m,k,q;
    if (scanf("%d%d%d%d", &n, &m, &k, &q) != 4) return 0;
    for (size_t i = 0; i < n; i++) {
        teams[i].id = i+1;
        scanf(" %s", teams[i].name);
    }

    for (size_t i = 0; i < m; i++) {
        int t,id;
        char question_char, v[RESULT_LEGTH_LIMIT];
        scanf("%d%d %c %s", &t, &id, &question_char, v);
        id --;
        int p = question_char - 'A';

        if (strcmp(v, "CE")==0 || teams[id].question[p].is_AC==true) {
            continue;
        }
        else if (strcmp(v, "AC")==0) {
            teams[id].question[p].is_AC = true;
            teams[id].question[p].AC_time = t;
            teams[id].AC_count ++;
            teams[id].punish += t+20*teams[id].question[p].WA_count;
            continue;
        }
        else {
            teams[id].question[p].WA_count ++;
            continue;
        }

    }
    qsort(teams, n, sizeof(teams[0]), cmp_record);
    for (size_t i = 0; i < q; i++) {
        int r;
        scanf("%d", &r);
        r--;
        printf("%d %s %d %d\n", teams[r].id, teams[r].name, teams[r].AC_count, teams[r].punish);
    }
    return 0;
}
