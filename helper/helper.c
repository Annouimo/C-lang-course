#include <stdio.h>

//start
int clean_gets(char * string){
    return scanf(" %[^\n]", string);
}

int clean_getchar(char * ch){
    return scanf(" %c", ch);
}
//end

int main(void){
    char ch;
    printf("clean_getchar demonstration:\n");
    clean_getchar(&ch);
    printf("%c\n", ch);

    printf("clean_gets demostration:\n");
    char string[100];
    clean_gets(string);
    printf("%s", string);
    return 0;
}
