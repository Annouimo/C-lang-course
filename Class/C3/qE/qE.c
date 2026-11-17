#include <stdio.h>

void print_bite(int number_bite[]);
void origin_bite(int number, int number_bite[]);
void reverse_bite(int number, int number_bite[]);
void full_bite(int number, int number_bite[]);

int main(void){
    long long int n_in;
    scanf("%lld", &n_in);

    if(n_in<-2147483648 || n_in>=2147483648){
        printf("N0NE N0NE N0NE");
        return 0;
    }
    else if (n_in == -2147483648) {
        printf("N0NE N0NE 10000000000000000000000000000000");
        return 0;
    }
    int n = n_in;

    int result[32];
    origin_bite(n, result);
    print_bite(result);
    reverse_bite(n, result);
    print_bite(result);
    full_bite(n, result);
    print_bite(result);
    return 0;
}

void print_bite(int number_bite[]){
    for (int i = 0; i<32; i++) {
        printf("%d", number_bite[i]);
    }
    printf(" ");
}

void origin_bite(int number, int number_bite[]){
    if (number>=0) {
        number_bite[0]=0;
    }
    else {
        number_bite[0]=1;
        number *= -1;
    }
    for (int i = 1; i<32; i++) {
        number_bite[32-i] =  number%2;
        number /= 2;
    }
}

void reverse_bite(int number, int number_bite[]){
    origin_bite(number, number_bite);
    if (number>=0) return;
    number_bite[0]=0;
    for (int i = 0; i<32; i++) {
        number_bite[i] = 1-number_bite[i];
    }
}

void full_bite(int number, int number_bite[]){
    reverse_bite(number, number_bite);
    if (number>=0) {
        return;
    }
    number_bite[31] ++;
    for (int i = 31; i>=0; i--) {
        if(number_bite[i]==2) {
            number_bite[i] = 0;
            if (i==0) {
                break;
            }
            number_bite[i-1]++;
        };
    }
}
