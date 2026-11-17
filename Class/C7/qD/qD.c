#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum{
    STRING_LENGTH_LIMIT = 100005,
    STRING_COUNT_LIMIT = 11,
};

int main(void){
    size_t n;
    scanf("%zu", &n);
    char data[STRING_COUNT_LIMIT][STRING_LENGTH_LIMIT];
    size_t index_dict[STRING_COUNT_LIMIT];
    for (size_t i = 1; i <= n; i++) {
        scanf(" %s", data[i]);
        index_dict[i] = i;
    }

    size_t m;
    scanf("%zu", &m);

    char operation;
    size_t index_i, index_j;
    size_t temp;
    for (size_t i = 0; i < m; i++) {
        scanf(" %c", &operation);
        switch (operation) {
            case 'S':
                scanf("%zu%zu", &index_i, &index_j);
                temp = index_dict[index_i];
                index_dict[index_i] = index_dict[index_j];
                index_dict[index_j] = temp;
                break;
            case 'Q':
                scanf("%zu", &index_i);
                printf("%s\n", data[index_dict[index_i]]);
                break;
        }
    }
    return 0;
}
