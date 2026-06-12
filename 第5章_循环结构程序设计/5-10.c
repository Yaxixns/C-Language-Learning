/*
 * 习题10
 * 有一个分数序列：
 *   2/1, 3/2, 5/3, 8/5, 13/8, 21/13, ...
 * 求出这个数列的前 20 项之和。
 */

#include <stdio.h>

int main()
{
    float sum = 0;
    int i;
    int temp1 = 2, temp2 = 1, next;
    for (i = 1; i <= 20; i++)
    {
        sum += (float)temp1 / (float)temp2;
        next = temp1 + temp2;
        temp2 = temp1;
        temp1 = next;
    }

    printf("%.3f\n", sum);
    getchar();
    return 0;
}
/* ────────────────────────────────────────
 * 📝 批改评语：✅ 正确！10/10
 *
 * ① 分数序列是斐波那契分子/分母，递推正确
 * ② 显式 (float) 强制转换避免整数除法 — 好习惯
 * ──────────────────────────────────────── */
