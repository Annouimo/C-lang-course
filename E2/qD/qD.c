#include <stdio.h>

int main(void)
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        printf("%c", ch);
    }
    return 0;
}