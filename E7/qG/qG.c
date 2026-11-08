#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{
    STRING_LENGTH_LIMIT = 25,
    STRING_COUNT_LIMIT = 100010,
};

struct String{
    char data[STRING_LENGTH_LIMIT];
    size_t position;
    size_t length;
};
int String_init(struct String * string, FILE * stream, size_t position);

struct Index {
    size_t origin_index;
    size_t final_index;
};

int compare(const void *p,const void *q);
int compare_index(const void *p,const void *q){
    return ((struct Index *)p)->origin_index - ((struct Index *)q)->origin_index;
}

int main(void){
    size_t n, q;
    scanf("%zu%zu", &n, &q);

    struct String line[STRING_COUNT_LIMIT];
    for (size_t i = 0; i < n; i++) {
        String_init(&(line[i]), stdin, i+1);
    }
    qsort(line, n, sizeof(line[0]), compare);
    for (size_t i = 0; i < n; i++) {
        printf("%s\n", line[i].data);
    }

    struct Index index_list[STRING_COUNT_LIMIT];
    for (size_t i = 0; i < n; i++) {
        index_list[i].final_index = i+1;
        index_list[i].origin_index = line[i].position;
    }
    qsort(index_list, n, sizeof(index_list[0]), compare_index);

    size_t index;
    for (size_t i = 0; i < q; i++) {
        scanf("%zu", &index);
        printf("%zu\n", index_list[index-1].final_index);
    }
    return 0;
}

int compare(const void *p,const void *q){
    struct String x=*(struct String *)p;
    struct String y=*(struct String *)q;
    if (x.length != y.length) {
        return x.length > y.length;
    }
    return strcmp(x.data, y.data);
}

int String_init(struct String * string, FILE * stream, size_t position){
    fscanf(stream, " %s", string->data);
    string->position = position;
    string->length = strlen(string->data);
    return 0;
}
