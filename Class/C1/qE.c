#include <stdio.h>

int main(){
    int F, I, M, score;
    
    scanf("%d%d%d", &F, &I, &M);
    score = F*20 + I*10 + M*5;
    if (score > 15){
        printf("WA");
    } else if (I == 0)
    {
        printf("OE");
    }
    else {
        printf("AC");
    }
    return 0;
}