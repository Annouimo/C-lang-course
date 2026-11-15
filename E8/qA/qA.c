#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char taikongnauts[25][3][30] = {
    {"UNMANNED", "UNMANNED", "UNMANNED"},
    {"UNMANNED", "UNMANNED", "UNMANNED"},
    {"UNMANNED", "UNMANNED", "UNMANNED"},
    {"UNMANNED", "UNMANNED", "UNMANNED"},
    {"Yang Liwei", "UNMANNED", "UNMANNED"},
    {"Fei Junlong", "Nie Haisheng", "UNMANNED"},
    {"Zhai Zhigang", "Liu Boming", "Jing Haipeng"},
    {"UNMANNED", "UNMANNED", "UNMANNED"},
    {"Jing Haipeng", "Liu Wang", "Liu Yang"},
    {"Nie Haisheng", "Zhang Xiaoguang", "Wang Yaping"},
    {"Jing Haipeng", "Chen Dong", "UNMANNED"},
    {"Nie Haisheng", "Liu Boming", "Tang Hongbo"},
    {"Zhai Zhigang", "Wang Yaping", "Ye Guangfu"},
    {"Chen Dong", "Liu Yang", "Cai Xuzhe"},
    {"Fei Junlong", "Deng Qingming", "Zhang Lu"},
    {"Jing Haipeng", "Zhu Yangzhu", "Gui Haichao"},
    {"Tang Hongbo", "Tang Shengjie", "Jiang Xinlin"},
    {"Ye Guangfu", "Li Cong", "Li Guangsu"},
    {"Cai Xuzhe", "Song Lingdong", "Wang Haoze"},
    {"Chen Dong", "Chen Zhongrui", "Wang Jie"},
    {"Zhang Lu", "Wu Fei", "Zhang Hongzhang"},
    {"RESCUE", "RESCUE", "RESCUE"},
    {"Zhu Yangzhu", "Zhang Zhiyuan", "Li Jiaying"},
    {"PLANNING","PLANNING","PLANNING"}
};

int main(void) {
    int a, b;
    while (scanf("%d" "%d", &a, &b) == 2) {
        printf("%s\n", taikongnauts[a-1][b-1]);

    }
    return 0;
}
