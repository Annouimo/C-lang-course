#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);

    int prevstop[26];
    for (int i=0; i<26; i++) {
        prevstop[i] = -1;
    }
    char start, end;
    for (int i = 0; i<n; i++) {
        scanf(" %c""->""%c", &start, &end);
        prevstop[end-'A'] = start-'A';
    }
    scanf(" %c"" ""%c", &start, &end);
    int st = (int)start-'A';
    int ed  = (int)end - 'A';
    while (1) {
        if (ed == -1) {
            printf("Sorry!");
            return 0;
        }
        if (ed == st) {
            printf("Don't stay up too late!");
            return 0;
        }
        ed = prevstop[ed];
    }

}
