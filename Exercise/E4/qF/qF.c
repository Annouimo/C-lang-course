#include <stddef.h>
#include <stdio.h>

int main(void){
    unsigned int n = 0;
    scanf("%u", &n);
    unsigned int data[3][3] = {0};
    unsigned int age = 0, gender = 0;
    for (size_t i = 0; i < n; i++) {
        scanf("%u %u", &age, &gender);
        data[age][gender]++;
    }
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            printf("%u ", data[i][j]);
        }
        printf("\n");
    }
    return 0;
}
