/*
 * 习题9
 * 写一函数，将一个 3x3 的整型矩阵转置。
 * （要求用指针方法处理）
 */

#include <stdio.h>

int main()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j, temp;
    printf("原数组：\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", *(*(a + i) + j));
        }
        printf("\n");
    }
    for (i = 0; i < 3; i++)
    {
        for (j = i; j < 3; j++)
        {
            temp = *(*(a + i) + j);
            *(*(a + i) + j) = *(*(a + j) + i);
            *(*(a + j) + i) = temp;
        }
    }
    printf("新数组：\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", *(*(a + i) + j));
        }
        printf("\n");
    }

    getchar();
    return 0;
}
