/*
 * 习题16
 * 输出以下图案：
 *      *
 *     ***
 *    *****
 *   *******
 *    *****
 *     ***
 *      *
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, d, stars;
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        d = abs(i - (n + 1) / 2);        // 距中间行的距离
        stars = n - 2 * d;               // 本行星号数

        for (j = 0; j < d; j++)          // 前面的空格
            printf(" ");
        for (j = 0; j < stars; j++)      // 星号
            printf("*");
        printf("\n");
    }

    getchar();
    getchar();
    return 0;
}


/* ────────────────────────────────────────
 * 📝 批改评语：✅ 正确！还泛化了 10/10
 *
 * ① 公式 stars=n-2*abs(i-mid) 精妙！一行算出每行星号数
 * ② 两个 getchar() — 前一个吃换行，后一个暂停，细节到位
 * ③ 题目只要求固定图案，你扩展为通用 n 行菱形，进阶了
 * ──────────────────────────────────────── */
