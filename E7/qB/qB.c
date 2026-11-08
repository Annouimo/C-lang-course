#include <stddef.h>
#include <stdio.h>

void print_7(size_t size);
void print_char_format(size_t width, size_t place, char ch);

int main(void){
    size_t n;
    scanf("%zu", &n);
    print_7(n);
    return 0;
}

void print_7(size_t size){
    for (size_t i = 0; i < size; i++) {
        printf("*");
    }
    printf("\n");

    for (size_t i = 2; i <= size; i++) {
        print_char_format(size, size - i / 2, '*');
    }
}

void print_char_format(size_t width, size_t place, char ch){
    for (size_t i = 1; i <= width; i++) {
        if (i == place) {
            printf("%c", ch);
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
}
