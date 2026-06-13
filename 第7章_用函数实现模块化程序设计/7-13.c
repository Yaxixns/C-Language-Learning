/*
 * 习题13
 * 用递归方法求 n 阶勒让德多项式的值。递归公式为：
 *   p_0(x) = 1
 *   p_1(x) = x
 *   p_n(x) = ((2n-1) * x * p_{n-1}(x) - (n-1) * p_{n-2}(x)) / n   (n >= 1)
 */

#include <stdio.h>

float p(int n, float x)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }
    else
    {
        return ((2 * n - 1) * x * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
    }
}

int main()
{
    int n;
    float x;
    printf("请输入 n 和 x：");
    scanf("%d%f", &n, &x);
    printf("P_%d(%.2f) = %.4f\n", n, x, p(n, x));

    getchar();
    getchar();
    return 0;
}
/* ✅ 10/10 勒让德多项式递归正确！P0和P1做基案，公式实现无误 */
