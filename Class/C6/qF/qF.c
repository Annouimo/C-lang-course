#include <stdio.h>
#include <stddef.h>

double cal_one_GPA(double my_score);
double five_grade_map[5] = {4.00, 3.50, 2.80, 1.70, 0.00};

int main(void){
    double class_score, my_score;
    char string[20];
    double sum_ps=0, sum_s=0;
    while (scanf("%lf%s", &class_score, string)!=EOF) {
        if ('A'<=string[0]&&string[0]<='E') {
            sum_ps += class_score * five_grade_map[string[0]-'A'];
            sum_s += class_score;
        }
        else if (string[0]=='P' || string[0]=='N') {
            continue;
        }
        else {
            sscanf(string, "%lf", &my_score);
            sum_ps += class_score * cal_one_GPA(my_score);
            sum_s += class_score;
        }

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
