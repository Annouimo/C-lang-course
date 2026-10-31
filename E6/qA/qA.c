#include <_stdio.h>
#include <stdio.h>
#include <string.h>

enum{
    STRING_LENGTH_LIMIT = 101,
};

int main(void){
    char string[STRING_LENGTH_LIMIT];
    fgets(string, STRING_LENGTH_LIMIT, stdin);
    if (strstr(string, "man")==NULL) {
        printf("mmk");
    }
    else {
        printf("52");
    }
    return 0;
}
