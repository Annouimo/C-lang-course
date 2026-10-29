#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum{
    STRING_LENGTH = 1010,
};

bool is_cake(char* key);

int main(void){
    char string[STRING_LENGTH] = {};
    fgets(string, STRING_LENGTH, stdin);
    size_t len_string = strlen(string)-1;

    bool is_print = false;
    for (size_t i = 0; i<len_string; i++) {
        if (is_cake(&string[i])) {
            i += 3;
        }
        else {
            printf("%c", string[i]);
            is_print = true;
        }
    }
    if(!is_print){
        printf("EMPTY");
    }
    return 0;
}

bool is_cake(char* key){
    if (
        *(key+0) == 'c' &&
        *(key+1) == 'a' &&
        *(key+2) == 'k' &&
        *(key+3) == 'e'
    ) {
        return true;
    }
    else {
        return false;
    }
}
