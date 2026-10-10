#include <stdio.h>

int number_to_twos_complement(int number);
int twos_complement_to_number(int twos_complement);

int main(void){
    int mode, n, result;
    scanf("%d%d", &mode, &n);
    switch (mode) {
        case 0:
            printf("%08d", number_to_twos_complement(n));
            break;
        case 1:
            printf("%d", twos_complement_to_number(n));
            break;
    }
    return 0;
}

int number_to_twos_complement(int number){
    number = (number+256)%256;
    int result=0, digit = 1;
    while (number != 0) {
        result += (number%2)*digit;
        number /=2;
        digit*=10;
    }
    return result;
}

int twos_complement_to_number(int twos_complement){
    int digit = 1, result = 0;
    while (twos_complement!=0) {
        result += (twos_complement%2) * digit;
        twos_complement /= 10;
        digit*=2;
    }
    if (result>=128) {
        result -= 256;
    }
    return result;
}
