#include <stdio.h>
#include <string.h>

enum Note{A,B,C,D,E,F,G};
char notes[7][5] = {"A", "B", "C", "D", "E", "F", "G"};
const int string[4][5] = {{G,A,B,C,D},{D,E,F,G,A},{A,B,C,D,E},{E,F,G,A,B}};

char * query(int s, int f){
    return notes[string[s-1][f]];
}

void add(char note, char * symbol){
    enum Note note_number = note-'A';
    strcat(notes[note_number], symbol);
}

int main(void){
    int tests;
    if (scanf("%d", &tests) != 1) return 0;
    while (tests--) {
        char note, symbol[5];
        scanf(" %c %s", &note, symbol);
        add(note, symbol);
    }

    if (scanf("%d", &tests) != 1) return 0;
    while (tests--) {
        int s,f;
        scanf("%d%d", &s, &f);
        printf("%s\n", query(s, f));
    }
}
