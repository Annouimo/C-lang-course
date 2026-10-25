#include <stddef.h>
#include <stdio.h>

struct SecretSlice {
    unsigned int number;
    unsigned long long int digit;
    unsigned int generation;
};

void query_secret(struct SecretSlice* secret_slice);
void encrypt_digit(struct SecretSlice* secret_slice);
unsigned long long int pow_2(unsigned int exponent);

int main(void){
    size_t T;
    scanf("%zu", &T);
    struct SecretSlice secret_slice;
    for (size_t i = 0; i<T; i++) {
        scanf("%u%llu", &secret_slice.generation, &secret_slice.digit);
        secret_slice.digit = pow_2(secret_slice.generation+1)-secret_slice.digit;
        query_secret(&secret_slice);
        printf("%u\n", secret_slice.number);
    }
    return 0;
}

void query_secret(struct SecretSlice* secret_slice){
    unsigned long long int middle_digit = pow_2(secret_slice->generation);
    if (secret_slice->digit == middle_digit) {
        secret_slice->number = secret_slice->generation % 10;
        return;
    }
    else if (secret_slice->digit > middle_digit) {
        struct SecretSlice next_query = {
            .digit = secret_slice->digit - middle_digit,
            .generation = secret_slice->generation - 1,
        };
        query_secret(&next_query);
        secret_slice->number = next_query.number;
        return ;
    }
    else {
        secret_slice->generation --;
        encrypt_digit(secret_slice);
        secret_slice->generation ++;
        return ;
    }
}

void encrypt_digit(struct SecretSlice* secret_slice){
    secret_slice->digit = pow_2(secret_slice->generation+1)-secret_slice->digit;
    query_secret(secret_slice);
    secret_slice->number = 9-secret_slice->number;
}

unsigned long long int pow_2(unsigned int exponent){
    return 1llu<<exponent;
}
