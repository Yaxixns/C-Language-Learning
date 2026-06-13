/*
 * 习题1
 * 用筛选法求 100 之内的素数。
*/


#include <stdio.h>

int main()
{
    int a[101], i, j;
    for (i = 2; i <= 100; i++)     // 先假设全是素数
        a[i] = 1;

    for (i = 2; i * i <= 100; i++) // 筛到 sqrt(100) 即可
        if (a[i])
            for (j = i * i; j <= 100; j += i)
                a[j] = 0;          // 筛掉 i 的倍数

    for (i = 2; i <= 100; i++)
        if (a[i])
            printf("%d ", i);
    printf("\n");

    getchar();
    return 0;
}

/* ✅ 10/10 筛选法正确！① 数组作素数标记位 ② i*i<=100 筛到sqrt(100) ③ 内层从i*i开始跳过量筛 — 三点全是标准优化 */
