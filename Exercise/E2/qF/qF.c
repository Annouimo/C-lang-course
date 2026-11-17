#include <stdio.h>

int main(void)
{
    int n;
    char op;
    int a, b;
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        scanf(" %c%d%d", &op, &a, &b);
        if (op == '+')
        {
            printf("%d\n", a + b);
        }
        else if (op == '-')
        {
            printf("%d\n", a - b);
        }
        else if (op == '*')
        {
            printf("%d\n", a * b);
        }
        else if (op == '/')
        {
            printf("%d\n", a / b);
        }
    }
    return 0;
}