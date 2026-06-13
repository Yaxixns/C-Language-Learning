/*
 * 习题14
 * 将 n 个数按输入时顺序的逆序排列，用函数实现。
 * （要求用指针方法处理）
 */

#include <stdio.h>

void reverse(int *a, int n)
{
    int i, temp;
    for (i = 0; i < n / 2; i++)
    {
        temp = *(a + i);
        *(a + i) = *(a + n - 1 - i);
        *(a + n - 1 - i) = temp;
    }
}

int main()
{
    int a[100], n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", a + i);

    reverse(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", *(a + i));

    getchar();
    return 0;
}
/* ✅ 10/10 指针逆序正确！*(a+i)↔*(a+n-1-i)对称交换，n/2次循环 */
