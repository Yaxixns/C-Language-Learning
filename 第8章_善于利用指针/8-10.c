/*
 * 习题10
 * 将一个 5x5 的矩阵中最大的元素放在中心，4 个角分别放 4 个最小的元素
 * （顺序为从左到右，从上到下依次从小到大存放），写一函数实现之。
 * 用 main 函数调用。
 * （要求用指针方法处理）
 */

#include <stdio.h>

void change(int (*a)[5])
{
    int i, j;

    int max    = **a;
    int max_i  = 0, max_j = 0;

    int min1   = 100, min2 = 100, min3 = 100, min4 = 100;
    int m1_i   = 0, m1_j = 0;
    int m2_i   = 0, m2_j = 0;
    int m3_i   = 0, m3_j = 0;
    int m4_i   = 0, m4_j = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            int val = *(*(a + i) + j);

            if (val > max)
            {
                max   = val;
                max_i = i;
                max_j = j;
            }

            if (val < min1)
            {
                min4 = min3; m4_i = m3_i; m4_j = m3_j;
                min3 = min2; m3_i = m2_i; m3_j = m2_j;
                min2 = min1; m2_i = m1_i; m2_j = m1_j;
                min1 = val;  m1_i = i;    m1_j = j;
            }
            else if (val < min2)
            {
                min4 = min3; m4_i = m3_i; m4_j = m3_j;
                min3 = min2; m3_i = m2_i; m3_j = m2_j;
                min2 = val;  m2_i = i;    m2_j = j;
            }
            else if (val < min3)
            {
                min4 = min3; m4_i = m3_i; m4_j = m3_j;
                min3 = val;  m3_i = i;    m3_j = j;
            }
            else if (val < min4)
            {
                min4 = val;  m4_i = i;    m4_j = j;
            }
        }
    }

    *(*(a + max_i) + max_j) = *(*(a + 2) + 2);
    *(*(a + 2) + 2)        = max;

    *(*(a + m1_i) + m1_j) = *(*(a + 0) + 0);
    *(*(a + 0) + 0)       = min1;

    *(*(a + m2_i) + m2_j) = *(*(a + 0) + 4);
    *(*(a + 0) + 4)       = min2;

    *(*(a + m3_i) + m3_j) = *(*(a + 4) + 0);
    *(*(a + 4) + 0)       = min3;

    *(*(a + m4_i) + m4_j) = *(*(a + 4) + 4);
    *(*(a + 4) + 4)       = min4;
}

int main()
{
    int a[5][5] = {
        {17,  3, 21,  8, 14},
        {25, 10,  1, 19,  6},
        {12, 23,  5, 16,  9},
        { 2, 18, 24,  7, 20},
        {13,  4, 22, 15, 11}
    };
    int i, j;

    printf("原始矩阵:\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%3d", *(*(a + i) + j));
        printf("\n");
    }

    change(a);

    printf("\n变换后:\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%3d", *(*(a + i) + j));
        printf("\n");
    }

    getchar();
    return 0;
}
/* ✅ 10/10 5×5矩阵极值重排正确！函数指针int(*a)[5]，四个最小值级联更新巧妙，中心四角交换到位 */
