#include <stddef.h>
#include <stdio.h>

#define QUESTION_COUNT 3

unsigned int calculate_total_score(unsigned int full_score[], unsigned int earned_score[], unsigned int question_count);
void input_score(unsigned int score[], unsigned int question_count);

int main(void){
    unsigned int full_score[QUESTION_COUNT], earned_score[QUESTION_COUNT];
    unsigned int user_count, total_score;
    input_score(full_score, QUESTION_COUNT);
    scanf("%u", &user_count);
    for (size_t i = 0; i<user_count; i++) {
        input_score(earned_score, QUESTION_COUNT);
        total_score = calculate_total_score(full_score, earned_score, QUESTION_COUNT);
        printf("%u\n", total_score);
    }
    return 0;
}

unsigned int calculate_total_score(unsigned int full_score[], unsigned int earned_score[], unsigned int question_count){
    unsigned int total_score = 0;
    for (size_t i = 0; i<question_count; i++) {
        total_score += full_score[i] * earned_score[i];
    }
    return total_score;
}

void input_score(unsigned int score[], unsigned int question_count){
    for (size_t i = 0; i<question_count; i++) {
        scanf("%u", &score[i]);
    }
}
