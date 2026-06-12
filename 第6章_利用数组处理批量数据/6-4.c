/*
 * 习题4
 * 有一个已排好序的数组，要求输入一个数后，按原来排序的规律将它插入数组中。
*/

#include <stdio.h>

int main()
{
    int a[11] = {1, 4, 6, 8, 10, 12, 15, 18, 20, 25}; // 已有 10 个
    int x, i, j;
    scanf("%d", &x);

    for (i = 0; i < 10; i++)        // 找插入位置
        if (x < a[i])
            break;

    for (j = 10; j > i; j--)        // 后面元素后移
        a[j] = a[j - 1];
    a[i] = x;                       // 插入

    for (i = 0; i < 11; i++)
        printf("%d ", a[i]);
    printf("\n");

    getchar();
    getchar();
    return 0;
}

