#include <stdio.h>
#include <stddef.h>

double cal_one_GPA(double my_score);

int main(void){
    double class_score, my_score;
    double sum_ps=0, sum_s=0;
    while (scanf("%lf%lf", &class_score, &my_score)!=EOF) {
        sum_ps += class_score * cal_one_GPA(my_score);
        sum_s += class_score;
    }
    double gpa = sum_ps/sum_s;
    printf("%.2lf", gpa);
    return 0;
}

double cal_one_GPA(double my_score){
    if(my_score < 60){
        return 0.0;
    }
    else {
        return 4.0-((3.0*(100.0-my_score)*(100.0-my_score))/1600.0);
    }
}
