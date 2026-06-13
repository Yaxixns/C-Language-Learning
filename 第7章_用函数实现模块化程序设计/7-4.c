/*
 * 习题4
 * 写一个函数，使给定的一个 3x3 的二维整型数组转置，即行列互换。
 */

#include <stdio.h>

void transpose(int a[3][3])
{
    int i, j, t;
    for (i = 0; i < 3; i++)
        for (j = i + 1; j < 3; j++)
        {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
}

int main()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j;

    printf("原矩阵：\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }

    transpose(a);

    printf("转置后：\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }

    getchar();
    return 0;
}
