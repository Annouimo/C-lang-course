#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum{
    STRING_LENGTH_LIMIT = 1005,
};

bool is_reverse(char string[], size_t length);

int main(void){
    char string[STRING_LENGTH_LIMIT];
    size_t len_str = 0;
    while (fgets(string, STRING_LENGTH_LIMIT, stdin) != NULL) {
        len_str = strlen(string)-1;
        if (is_reverse(string, len_str)) {
            printf("yea\n");
        }
        else {
            printf("nah\n");
        }
    }
}

bool is_reverse(char string[], size_t length){
    for (size_t i = 0; i < length/2; i++) {
        if (string[i]!=string[length-i-1]) {
            return false;
        }
    }
    return true;
}
