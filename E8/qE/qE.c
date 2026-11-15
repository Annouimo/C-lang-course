#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
    STRING_LENGTH_LIMIT = 100,
};

int main(void) {
    int tests;
    if (scanf("%d", &tests) != 1) return 0;
    while (tests--) {
        char command[10], string[STRING_LENGTH_LIMIT];
        scanf(" %s %s", command, string);
        if (strcmp(command, "len") == 0) {
            printf("%lu", strlen(string));
        }
        else if (strcmp(command, "cpy") == 0) {
            int n; scanf("%d", &n);
            char result[STRING_LENGTH_LIMIT] = {0};
            strncpy(result, string, n);
            printf("%s", result);
        }
        else if (strcmp(command, "cat") == 0) {
            char t[STRING_LENGTH_LIMIT]; scanf(" %s", t);
            strcat(string, t);
            printf("%s", string);
        }
        else if (strcmp(command, "cmp") == 0) {
            char t[STRING_LENGTH_LIMIT]; scanf(" %s", t);
            int cmp_result = strcmp(string, t);
            if (cmp_result > 0) printf(">");
            else if (cmp_result == 0) printf("=");
            else printf("<");
        }
        else if (strcmp(command, "pos") == 0) {
            char t[STRING_LENGTH_LIMIT]; scanf(" %s", t);
            char * find_result = strstr(string, t);
            if (find_result == NULL) printf("0");
            else printf("%ld", (find_result-string)+1);
        }
        else if (strcmp(command, "chr") == 0) {
            char c; scanf(" %c", &c);
            char * find_result = strchr(string, c);
            if (find_result == NULL) printf("0");
            else printf("%ld", (find_result-string)+1);
        }
        printf("\n");
    }
    return 0;
}
