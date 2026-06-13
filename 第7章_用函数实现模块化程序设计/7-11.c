/*
 * 习题11
 * 写一个函数，用"起泡法"对输入的 10 个字符按由小到大顺序排列。
 */

#include <stdio.h>

void bubble_sort(char a[], int n)
{
    int i, j;
    char t;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int main()
{
    char a[11];    // 留一位给 \0（如果当字符串用）
    int i;

    printf("请输入10个字符：");
    for (i = 0; i < 10; i++)
        scanf("%c", &a[i]);

    bubble_sort(a, 10);

    printf("排序后：");
    for (i = 0; i < 10; i++)
        printf("%c ", a[i]);
    printf("\n");

    getchar();
    getchar();
    return 0;
}
/* ✅ 10/10 冒泡排序正确！经典双循环，char交换，两个getchar处理残留换行 */
