#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

enum{
    NOTE_COUNT_LIMIT = 110,
    NOTE_LENGTH_LIMIT = 120,
    STRING_COUNT_LIMIT = 114550,
};

struct Instrument {
    size_t string_count;
    uint32_t string_start[STRING_COUNT_LIMIT];
    size_t note_count;
    char note_name[NOTE_COUNT_LIMIT][NOTE_LENGTH_LIMIT];
};
struct Instrument init(void);
char * play(struct Instrument * instrument, size_t s, size_t f);
void change(struct Instrument * instrument, size_t i, char ch[]);

int main(void){
    struct Instrument instrument = init();
    size_t q;
    scanf("%zu", &q);

    uint32_t mode;
    size_t s,f;
    size_t index;
    char c[5];
    for (size_t i = 0; i < q; i++) {
        scanf("%u", &mode);
        switch (mode) {
            case 1:
                scanf("%zu%zu", &s, &f);
                printf("%s\n", play(&instrument, s, f));
                break;
            case 2:
                scanf("%zu %s", &index, c);
                change(&instrument, index, c);
                break;
        }
    }
    return 0;
}

struct Instrument init(void){
    struct Instrument instrument;
    scanf("%zu%zu", &instrument.string_count, &instrument.note_count);
    for (size_t i = 1; i <= instrument.string_count; i++) {
        scanf("%u", &(instrument.string_start[i]));
    }
    for (size_t i = 0; i < instrument.note_count; i++) {
        scanf(" %s", instrument.note_name[i]);
    }
    return instrument;
}

char * play(struct Instrument * instrument, size_t s, size_t f){
    size_t posotion = (instrument->string_start[s] + f)%(instrument->note_count);
    return instrument->note_name[posotion];
}

void change(struct Instrument * instrument, size_t i, char ch[]){
    strcat(instrument->note_name[i], ch);
}
