/*
 * 习题4
 * 有 n 个整数，使前面各数顺序向后移 m 个位置，最后 m 个数变成最前面 m 个数。
 * 写一函数实现以上功能，在主函数中输入 n 个整数和输出调整后的 n 个数。
 * （要求用指针方法处理）
 */

#include <stdio.h>

void move(int *arr, int n, int m)
{
    int temp[100];
    m = m % n;

    for (int i = 0; i < m; i++)
    {
        *(temp + i) = *(arr + (n - m) + i);
    }

    for (int i = n - 1; i >= m; i--)
    {
        *(arr + i) = *(arr + i - m);
    }

    for (int i = 0; i < m; i++)
    {
        *(arr + i) = *(temp + i);
    }
}

int main()
{
    int arr[100];
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }

    move(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return 0;
}