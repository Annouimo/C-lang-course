#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_MAX 105

typedef struct  {
    int row_begin;
    int row_end;
    int col_begin;
    int col_end;
} Rectangle ;

int calculate_matrix_rectangle(int matrix[MATRIX_MAX][MATRIX_MAX], Rectangle rec);
bool is_rectangle_valid(Rectangle rec);

int main(void) {
    static int matrix[MATRIX_MAX][MATRIX_MAX];
    int rows, cols;
    scanf("%d%d", &rows, &cols);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) scanf("%d", &matrix[r][c]);
    }
    Rectangle rec = {
        .row_begin = 0,
        .col_begin = 0,
        .row_end = rows-1,
        .col_end = cols-1,
    };
    while (is_rectangle_valid(rec)) {
        printf("%d ", calculate_matrix_rectangle(matrix, rec));
        rec.col_begin ++;
        rec.row_begin ++;
        rec.col_end --;
        rec.row_end --;
    }
    printf("\n");
    return 0;
}

int calculate_matrix_rectangle(int matrix[MATRIX_MAX][MATRIX_MAX], Rectangle rec){
    int sum = 0;
    for (int r = rec.row_begin; r <= rec.row_end; r++) {
        sum += matrix[r][rec.col_begin];
        if (rec.col_begin != rec.col_end) {
            sum += matrix[r][rec.col_end];
        }
    }
    for (int c = rec.col_begin+1; c <= rec.col_end-1; c++){
        if (c > rec.col_end+1) {
            break;
        }
        sum += matrix[rec.row_begin][c];
        if (rec.row_begin != rec.row_end) {
            sum += matrix[rec.row_end][c];
        }

    }
    return sum;
}

bool is_rectangle_valid(Rectangle rec){
    if (rec.col_begin > rec.col_end || rec.row_begin > rec.row_end) {
        return false;
    }
    return true;
}
