#include <stdio.h>

char f(int input1, int input2, int input3 , int height){
    if (input1 >= height)
    {
        return 'O';
    }
    else if (input2 >= height)
    {
        return 'O';
    }
    else if (input3 >= height)
    {
        return 'O';
    }
    else {
        return ' ';
    }
}

char g(int input){
    if (input >=1)
    {
        return 'O';
    }
    else {
        return ' ';
    }
}

int main(){
    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    scanf("%d%d%d%d%d%d%d%d%d", &a1, &a2, &a3, &b1, &b2, &b3, &c1, &c2, &c3);

    printf("%c%c%c|%c%c%c\n", f(a1,b1,c1,3),f(a2,b2,c2,3),f(a3,b3,c3,3), f(a1,a2,a3,3),f(b1,b2,b3,3),f(c1,c2,c3,3));
    printf("%c%c%c|%c%c%c\n", f(a1,b1,c1,2),f(a2,b2,c2,2),f(a3,b3,c3,2), f(a1,a2,a3,2),f(b1,b2,b3,2),f(c1,c2,c3,2));
    printf("%c%c%c|%c%c%c\n", f(a1,b1,c1,1),f(a2,b2,c2,1),f(a3,b3,c3,1), f(a1,a2,a3,1),f(b1,b2,b3,1),f(c1,c2,c3,1));
    printf("---+---\n");
    printf("%c%c%c|\n", g(a1),g(a2),g(a3));
    printf("%c%c%c|\n", g(b1),g(b2),g(b3));
    printf("%c%c%c|\n", g(c1),g(c2),g(c3));
}

