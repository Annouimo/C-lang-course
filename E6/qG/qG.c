#include <_stdio.h>
#include <_strings.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

enum{
    STRING_SIZE_LIMIT = 10005,
    NAME_SIZE_LIMIT = 25,
};

bool delete_string_in_string(char string[], char element[]);

int main(void){
    char string[STRING_SIZE_LIMIT];
    scanf("%s", string);
    size_t n;
    scanf("%zu", &n);
    char name[NAME_SIZE_LIMIT];
    for (size_t i = 0; i < n; i++) {
        scanf(" %s", name);
        while (delete_string_in_string(string, name)) {;}
    }
    printf("%s", string);
    return 0;
}

bool delete_string_in_string(char string[], char element[]){
    size_t element_size = strlen(element);
    char * index = strstr(string, element);
    if (index == NULL) {
        return false;
    }
    memmove(index, index+element_size, strlen(index+element_size)+1);
    return true;
}
