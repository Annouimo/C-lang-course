#include <stdio.h>

int main(){
    int input;
    scanf("%d", &input);
    while (input != 0)
    {
        printf("%d\n", input%10);
        input = input/10;
    }
    return 0;
}