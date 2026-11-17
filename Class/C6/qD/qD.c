#include <stddef.h>
#include <stdio.h>

enum{
    MATRIX_SIZE_LIMIT = 1000,
};

unsigned int A[MATRIX_SIZE_LIMIT][MATRIX_SIZE_LIMIT];
unsigned int B[MATRIX_SIZE_LIMIT][MATRIX_SIZE_LIMIT];
unsigned int AB[MATRIX_SIZE_LIMIT][MATRIX_SIZE_LIMIT];

void get_matrix(
    unsigned int matrix[][MATRIX_SIZE_LIMIT],
    unsigned int n, unsigned int m
);
void print_matrix(
    unsigned int matrix[][MATRIX_SIZE_LIMIT],
    unsigned int n, unsigned int m
);
void mateix_multiply(
    unsigned int A[][MATRIX_SIZE_LIMIT],
    unsigned int B[][MATRIX_SIZE_LIMIT],
    unsigned int AB[][MATRIX_SIZE_LIMIT],
    unsigned int n, unsigned int m, unsigned int p
);

int main(void){
    unsigned int n,m,p;
    scanf("%u%u%u", &n, &m, &p);
    get_matrix(A, n, m);
    get_matrix(B, m, p);
    mateix_multiply(A, B, AB, n, m, p);
    print_matrix(AB, n, p);
    return 0;
}

void get_matrix(
    unsigned int matrix[][MATRIX_SIZE_LIMIT],
    unsigned int n, unsigned int m
){
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            scanf("%u", &(matrix[i][j]));
        }
    }
}

void print_matrix(
    unsigned int matrix[][MATRIX_SIZE_LIMIT],
    unsigned int n, unsigned int m
){
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            printf("%u ", matrix[i][j]);
        }
        printf("\n");
    }
}

void mateix_multiply(
    unsigned int A[][MATRIX_SIZE_LIMIT],
    unsigned int B[][MATRIX_SIZE_LIMIT],
    unsigned int AB[][MATRIX_SIZE_LIMIT],
    unsigned int n, unsigned int m, unsigned int p
){
    unsigned int dot_product = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < p; j++) {
            dot_product = 0;
            for (size_t k = 0; k < m; k++) {
                dot_product += A[i][k] * B[k][j];
            }
            AB[i][j] = dot_product;
        }
    }
}
