/*
 * 习题5
 * 将一个数组中的值按逆序重新存放。
 * 例如，原来顺序为 8, 6, 5, 4, 1，要求改为 1, 4, 5, 6, 8。
 */

#include <stdio.h>

int main()
{
    int a[] = {8, 6, 5, 4, 1};
    int n = 5, i, t;
    for (i = 0; i < n / 2; i++)
    {
        t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    getchar();
    return 0;
}
/* ✅ 10/10 逆序正确！n/2次交换，a[i]↔a[n-1-i]对称公式无误 */
