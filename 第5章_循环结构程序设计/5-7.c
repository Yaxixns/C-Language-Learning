/*
 * 习题7
 * 求三个求和式的总和：
 *   sum(k)     for k=1 to 100
 *   sum(k^2)   for k=1 to 50
 *   sum(1/k)   for k=1 to 10
 */

#include <stdio.h>

int main()
{
    int sum1 = 0, sum2 = 0, i;
    float sum3 = 0;
    for (i = 1; i <= 100; i++)
    {
        sum1 += i;
        if (i <= 50)
        {
            sum2 += i * i;
            sum3 += 1.0 / i;
        }
    }

    printf("%d %d %.2f", sum1, sum2, sum3);
    getchar();
    return 0;
}
/* ────────────────────────────────────────
 * 📝 批改评语：⚠️ 有一个 bug！7/10
 *
 * ① 单个循环同时算三组求和 — 思路好
 * ② sum1 (1+...+100) 和 sum2 (1²+...+50²) 正确
 *
 * ⚠️ 关键bug：sum3 (1/k for k=1..10) 循环到了 k=50！
 *    if(i<=50) sum3+=1.0/i 应该把 sum3 单独用 i<=10 控制
 * ──────────────────────────────────────── */
