#include <stdio.h>

void reverse_bite(unsigned int digit, unsigned long long int *status);
void set_bite_1(unsigned int digit, unsigned long long int *status);
void set_bite_0(unsigned int digit, unsigned long long int *status);

int main(void){
    unsigned long long int S=0;
    unsigned int q, op, x;
    scanf("%u", &q);
    for (unsigned int i=0; i<q; i++) {
        scanf("%u%u", &op, &x);
        switch (op) {
            case 1:
                reverse_bite(x, &S);
                break;
            case 2:
                set_bite_1(x, &S);
                break;
            case 3:
                set_bite_0(x, &S);
                break;
        }
    }
    printf("%llu", S);
    return 0;
}

void reverse_bite(unsigned int digit, unsigned long long int *status){
    unsigned int digit_value = (*status>>digit)%2;
    switch (digit_value) {
        case 0:
            set_bite_1(digit, status);
            break;
        case 1:
            set_bite_0(digit, status);
            break;
    }
}
void set_bite_1(unsigned int digit, unsigned long long int *status){
    unsigned long long int help_number = (1LLu<<digit);
    *status |= help_number;
}
void set_bite_0(unsigned int digit, unsigned long long int *status){
    unsigned long long int help_number = ~(1LLu<<digit);
    *status &= help_number;
}
