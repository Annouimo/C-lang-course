#include <stddef.h>
#include <stdio.h>

int clean_gets(char * string){
    return scanf(" %[^\n]", string);
}

int clean_getchar(char * ch){
    return scanf(" %c", ch);
}

enum{
    STRING_LENGTH_LIMIT = 200010,
};

int main(void){
    char string[STRING_LENGTH_LIMIT];
    size_t pos;
    int status;
    do {
        scanf("%zu", &pos);
        status = clean_gets(&string[pos]);
    }while (status != EOF);
    printf("%s", string);
    return 0;
}
