/*
 * 习题2
 * 用选择法对 10 个整数排序。
 */

#include <stdio.h>

int main()
{
    int a[10], i, j, min, t;
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < 9; i++)
    {
        min = i;
        for (j = i + 1; j < 10; j++)
            if (a[j] < a[min])
                min = j;
        t = a[i];
        a[i] = a[min];
        a[min] = t;
    }

    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    printf("\n");

    getchar();
    getchar();
    return 0;
}
/* ✅ 10/10 选择排序正确！min标记最小下标，每轮只交换一次，两getchar()前吃换行后暂停 */
