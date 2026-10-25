#include <stdio.h>

void distribute_package(unsigned int initial, unsigned int capacity);

int main(void){
    unsigned int n,k;
    scanf("%u%u", &n, &k);
    distribute_package(n, k);
    return 0;
}

void distribute_package(unsigned int initial, unsigned int capacity){
    printf("%u ", initial);
    if (initial <= capacity) {
        return;
    }
    distribute_package(initial/2, capacity); // left
    distribute_package(initial-initial/2, capacity); //right
}
