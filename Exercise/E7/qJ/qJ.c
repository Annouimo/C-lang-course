#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int clean_gets(char * string){
    do {
        if (fgets(string, 2147483647, stdin)==NULL){
            return -1;
        }
    } while (string[0] == '\n' && string[1] == '\0');

    unsigned long length = strlen(string);
    if (string[length-1] == '\n') {
        string[length-1] = '\0';
    }
    return 0;
}

int clean_getchar(char * ch){
    return scanf(" %c", ch);
}

enum {
    STRING_COUNT_LIMIT = 15,
    STRING_LENGTH_LIMIT = 25,
    STRING_STACK_LENGTH_LIMIT = 10005,
    SLOGAN_COUNT_LIMIT = 100005,
};

struct String {
    char data[STRING_LENGTH_LIMIT];
    size_t length;
};
void initialize(struct String * string);

struct Range {
    size_t start;
    size_t end;
};

void count_fuck_after_name(
    char stack[],
    struct String name,
    struct String fuck[], size_t fuck_length,
    struct Range slogan[], size_t *count
);
bool is_in_array(struct Range range[], struct Range element, size_t count);

int main(void){
    size_t n,m;
    scanf("%zu%zu", &n, &m);
    struct String name[STRING_LENGTH_LIMIT];
    for (size_t i = 0; i < n; i++) {
        initialize(&name[i]);
    }
    struct String fuck[STRING_LENGTH_LIMIT];
    for (size_t i = 0; i < m; i++) {
        initialize(&fuck[i]);
    }
    char stack[STRING_STACK_LENGTH_LIMIT];
    clean_gets(stack);
    size_t stack_length = strlen(stack);

    size_t count = 0;
    struct Range slogan[SLOGAN_COUNT_LIMIT];
    for (size_t i = 0; i < n; i++) {
        count_fuck_after_name(stack, name[i], fuck, m, slogan, &count);
    }
    printf("%zu", count);
    return 0;
}

void initialize(struct String * string){
    clean_gets(string->data);
    string->length = strlen(string->data);
}

void count_fuck_after_name(
    char stack[],
    struct String name,
    struct String fuck[], size_t fuck_length,
    struct Range slogan[], size_t *count
){
    char * index = stack;
    struct Range range;
    while (1) {
        index = strstr(index, name.data);
        if (index == NULL) {
            return;
        }
        for (size_t i = 0; i < fuck_length; i++) {
            if (strncmp(index+name.length, fuck[i].data, fuck[i].length)==0) {
                range.start = index - stack;
                range.end = range.start + fuck[i].length + name.length;
                if (!is_in_array(slogan, range, *count)) {
                    slogan[*count] = range;
                    (*count) ++;
                }
            }
        }
        index ++;
    }
}

bool is_in_array(struct Range range[], struct Range element, size_t count){
    for (size_t i = 0; i < count; i++) {
        if (range[i].start == element.start && range[i].end == element.end) {
            return true;
        }
    }
    return false;
}
