#include <stdio.h>

int main(){
    int a, b, c, d, fx;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (int y = 10; y >= -10; y--)
    {
        for (int x = -5; x <= 5; x++)
        {
            fx = a*x*x*x+b*x*x+c*x+d;
            if (y == fx) printf("+");
            else if (y==0) printf("-");
            else if (x==0) printf("|");
            else printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}