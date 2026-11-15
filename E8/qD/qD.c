#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(void) {
    int tests;
    if (scanf("%d", &tests) != 1) return 0;
    char limit[20][2] = {};
    for (int i = 0; i < tests; i++) {
        scanf(" %c %c", &(limit[i][0]), &(limit[i][1]));
    }

    int count = 0;
    char valid_methods[20][3] = {};
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) {
        char competitors[3] = {'X'+i, 'X'+j, 'X'+k};
        if (competitors[0]==competitors[1] || competitors[1]==competitors[2] ||competitors[2] == competitors[0]) {
            continue;
        }
        bool is_valid = true;
        for (int ij = 0; ij < tests; ij++){
            if (limit[ij][1] == competitors[limit[ij][0]-'A']) {
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            for(int ij = 0; ij < 3; ij++) valid_methods[count][ij] = competitors[ij];
            count ++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("A-%c B-%c C-%c\n", valid_methods[i][0], valid_methods[i][1], valid_methods[i][2]);
    }
    return 0;
}
