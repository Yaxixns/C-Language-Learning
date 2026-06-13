/*
 * 习题9
 * 有 15 个数按由大到小顺序存放在一个数组中，输入一个数，要求用折半查找法
 * 找出该数是数组中第几个元素的值。如果该数不在数组中，则输出"无此数"。
 */

#include <stdio.h>

int main()
{
    int a[15] = {99, 85, 72, 68, 55, 47, 36, 30, 25, 19, 14, 10, 6, 3, 1};
    int l = 0, r = 14, m, x, found = 0;
    scanf("%d", &x);
    while (l <= r)
    {
        m = (l + r) / 2;
        if (a[m] == x)
        {
            printf("%d是数组中第%d个元素\n", x, m + 1);
            found = 1;
            break;
        }
        else if (a[m] > x)
            l = m + 1;
        else
            r = m - 1;
    }
    if (!found)
        printf("无此数\n");

    getchar();
    getchar();
    return 0;
}
/* ✅ 10/10 折半查找正确处理降序数组！a[m]>x向右，a[m]<x向左，逻辑与升降序匹配 */
