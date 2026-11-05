#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

enum {
    STRING_LENTH_LIMIT = 1010,
};

void swap_char(char *a, char *b);

int main(void){
    char string[STRING_LENTH_LIMIT] = {};
    fgets(string, STRING_LENTH_LIMIT, stdin);

    size_t word_begin_index=0, word_end_index=0;
    for (size_t i = 0; i < strlen(string); i++) {
        if (string[i] == ' ' || string[i] == '\n') {
            word_end_index = i-1;
            swap_char(&string[word_begin_index], &string[word_end_index]);
            word_begin_index = i+1;
        }
    }
    printf("%s", string);
    return 0;
}

void swap_char(char *a, char *b){
    char temp = *b;
    *b = *a;
    *a = temp;
}
