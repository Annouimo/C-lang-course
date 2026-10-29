#include <stddef.h>
#include <stdio.h>

enum{
    MATRIX_SIZE_LIMIT = 200,
    MATRIX_ELEMENT_LIMIT = 30,
};

int main(void){
    unsigned int n,m;
    char matrix[MATRIX_SIZE_LIMIT][MATRIX_SIZE_LIMIT][MATRIX_ELEMENT_LIMIT];
    scanf("%u%u", &n, &m);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            scanf("%s", matrix[i][j]);
        }
    }
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            printf("%s ", matrix[j][i]);
        }
        printf("\n");
    }
    return 0;
}
