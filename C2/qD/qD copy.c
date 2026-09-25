#include <stdio.h>

char move(char ch){
    if(!((('a' <= ch)&&(ch <= 'z'))||(('A' <= ch)&&(ch <= 'Z'))))
    {
        return ch;
    }
    else if (ch == 'z')
    {
        return 'a';
    }
    else if (ch == 'Z')
    {
        return 'A';
    }
    else{
        return ch +1;
    }
}

int main(){
    int k;
    scanf("%d", &k);
    k = k%26;
    char ch[100000];
    int i=0;
    getchar();
    while ((ch[i]=getchar()) != EOF)
    {
        i++;
    }
    
    for (size_t j = 0; j < i; j++)
    {
        for (size_t l = 0; l < k; l++)
        {
            ch[j] = move(ch[j]);
        }
        printf("%c", ch[j]);
    }
    printf("\n");
}