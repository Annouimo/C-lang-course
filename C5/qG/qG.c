#include <stddef.h>
#include <stdio.h>

static char starry_sky[1000][1000] = {0};

void fill_starry_sky(unsigned int n, unsigned int start_x, unsigned int start_y);
void print_starry_sky(unsigned int n);

int main(void){
    unsigned int n = 0;
    scanf("%u", &n);
    print_starry_sky(n);
    return 0;
}

void fill_starry_sky(unsigned int n, unsigned int start_x, unsigned int start_y){
    if (n==1) {
        starry_sky[start_x][start_y] = '*';
        return;
    }
    unsigned int m = n/3;
    fill_starry_sky(m, start_x, start_y);
    fill_starry_sky(m, start_x+2*m, start_y);
    fill_starry_sky(m, start_x+m, start_y+m);
    fill_starry_sky(m, start_x, start_y+2*m);
    fill_starry_sky(m, start_x+2*m, start_y+2*m);
}

void print_starry_sky(unsigned int n){
    fill_starry_sky(n, 0, 0);
    char ch;
    for (size_t i = 0; i<n; i++) {
        for (size_t j = 0; j<n; j++) {
            if (starry_sky[i][j] == '*') {
                ch = '*';
            }
            else {
                ch = ' ';
            }
            printf("%c", ch);
        }
        printf("\n");
    }
}
