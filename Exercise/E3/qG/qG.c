#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

#define LEN_SET 10

void number_to_setinfo(unsigned int number, unsigned int setinfo[]);
void print_set(unsigned int origin_set[] ,unsigned int setinfo[], unsigned int n);

int main(void){
    unsigned int n, a[LEN_SET] = {}, setinfo[LEN_SET] = {};
    scanf("%u", &n);
    for (size_t i = 0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (size_t i = 0; i<((size_t)1<<n); i++) {
        number_to_setinfo(i, setinfo);
        print_set(a, setinfo, n);
    }
    return 0;
}

void number_to_setinfo(unsigned int number, unsigned int setinfo[]){
    for (size_t i = 0; i<LEN_SET; i++) {
        setinfo[i] = (number>>i)&1u;
    }
}

void print_set(unsigned int origin_set[] ,unsigned int setinfo[], unsigned int n){
    printf("{");
    bool first_comma = false;
    for (size_t i =0; i<n; i++) {
        if (setinfo[i]!=0) {
            if (first_comma) {
                printf(",");
            }
            else {
                first_comma = true;
            }
            printf("%d", origin_set[i]);
        }
    }
    printf("}\n");
}
