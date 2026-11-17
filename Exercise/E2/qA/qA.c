#include <stdio.h>

int main(void){
    int n = 0;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        printf("#include <stdio.h>");
        break;
    case 2:
        printf("");
        break;
    case 3:
        printf("int main()");
        break;
    case 4:
        printf("{");
        break;
    case 5:
        printf("    printf(\"Our trail paves the rail starward!\");");
        break;
    case 6:
        printf("    return 0;");
        break;
    case 7:
        printf("}");
        break;
    default:
        break;
    }
    return 0;
}