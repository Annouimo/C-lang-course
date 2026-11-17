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
    long long int k;
    scanf("%lld", &k);
    k = k%26;
    char ch;
    getchar();
    while ((ch = getchar()) != EOF)
    {
        for (size_t i = 0; i < k; i++)
        {
            ch = move(ch);
        }
        printf("%c", ch);
    }
    
}