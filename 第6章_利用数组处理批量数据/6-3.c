/*
 * 习题3
 * 求一个 3x3 的整型矩阵对角线元素之和。
*/

#include <stdio.h>

int main()
{
    int a[3][3], i, j, sum = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < 3; i++)
        sum += a[i][i];              // 主对角线

    printf("sum = %d\n", sum);
    getchar();
    getchar();
    return 0;
}

/* ✅ 10/10 主对角线求和正确。题目未明确是否含副对角线，只求主对角线符合多数教材理解 */
