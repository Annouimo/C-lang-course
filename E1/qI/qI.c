#include <stdio.h>

int id_to_x(int id)
{
    int X[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    return X[id];
}
int id_to_y(int id)
{
    int Y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    return Y[id];
}

int xy_to_id(int x, int y)
{
    int M[3][3] = {
        {5, 6, 7},
        {4, -1, 0},
        {3, 2, 1}};
    return M[y + 1][x + 1];
}

int n, rin, bin, operation, r[2], b[2];

int turn(int A, int B, int C, int D)
{
    int tempx, tempy;
    tempx = A * r[0] + B * r[1];
    tempy = C * r[0] + D * r[1];
    r[0] = tempx;
    r[1] = tempy;

    tempx = A * b[0] + B * b[1];
    tempy = C * b[0] + D * b[1];
    b[0] = tempx;
    b[1] = tempy;
    return 0;
}

int main(void)
{

    scanf("%d%d%d", &n, &rin, &bin);
    r[0] = id_to_x(rin);
    r[1] = id_to_y(rin);
    b[0] = id_to_x(bin);
    b[1] = id_to_y(bin);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
            for (size_t i = 0; i < operation; i++)
            {
                turn(0,-1,1,0);
            }
            break;
        case 4:
            turn(1,0,0,-1);
            break;
        case 5:
            turn(0,1,1,0);
            break;
        case 6:
            turn(-1,0,0,1);
            break;
        case 7:
            turn(0,-1,-1,0);
            break;
        default:
            break;
        }
        printf("%d %d\n", xy_to_id(r[0],r[1]), xy_to_id(b[0],b[1]));
    }
}