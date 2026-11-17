#include <stdio.h>

int main()
{
    int input, ans[100], sum = 0;
    scanf("%d", &input);
    if (input == 0)
    {
        printf("0");
        return 0;
    }

    while (input != 0)
    {
        ans[sum] = input % 3;
        input = input / 3;
        sum++;
    }
    for (size_t i = 1; i <= sum; i++)
    {
        printf("%d", ans[sum - i]);
    }

    return 0;
}