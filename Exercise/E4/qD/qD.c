#include <stddef.h>
#include <stdio.h>

enum {DATA_SIZE = 100000};

enum grade{Excellent, Good, Pass, Fail, GRADE_COUNT, ValueError};
static const char *const grade_string[GRADE_COUNT] = {"Excellent", "Good", "Pass", "Fail"};
static enum grade get_student_grade(unsigned int score){
    if (90<=score && score<=100) return Excellent;
    else if (80<=score && score<=89) return Good;
    else if (60<=score && score<=79) return Pass;
    else if (0<=score && score<=59) return Fail;
    else return ValueError;
}

int main(void){
    unsigned int n=0;
    scanf("%u", &n);

    unsigned int student_id[GRADE_COUNT][DATA_SIZE];
    unsigned int student_count_grade[GRADE_COUNT] = {};
    unsigned int current_id, current_score;
    enum grade current_grade;
    for (size_t i = 0; i<n; i++) {
        scanf("%u %u", &current_id, &current_score);
        current_grade = get_student_grade(current_score);
        student_id[current_grade][student_count_grade[current_grade]] = current_id;
        student_count_grade[current_grade]++;
    }
    for (enum grade i = 0; i<GRADE_COUNT; i++) {
        printf("%s\n" , grade_string[i]);
        for (size_t j = 0; j<student_count_grade[i]; j++) {
            printf("%u\n", student_id[i][j]);
        }
    }
    return 0;
}
