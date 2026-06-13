/*
 * 习题12
 * 用牛顿迭代法求根。方程为 ax^3+bx^2+cx+d=0，系数 a,b,c,d 的值
 * 依次为 1,2,3,4，由主函数输入。求 x 在 1 附近的一个实根。
 * 求出根后由主函数输出。
 */

#include <stdio.h>
#include <math.h>

double newton(double a, double b, double c, double d)
{
    double x = 1.0, x0, f, f1;
    do
    {
        x0 = x;
        f  = ((a * x0 + b) * x0 + c) * x0 + d;   // ax³+bx²+cx+d
        f1 = (3 * a * x0 + 2 * b) * x0 + c;       // 3ax²+2bx+c（导数）
        x = x0 - f / f1;
    } while (fabs(x - x0) >= 1e-5);               // 精度到10⁻⁵

    return x;
}

int main()
{
    double a, b, c, d;
    printf("请输入系数 a b c d：");
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

    printf("根为：%.5f\n", newton(a, b, c, d));

    getchar();
    getchar();
    return 0;
}
/* ✅ 10/10 牛顿迭代法求根正确！Horner格式计算f和f，精度1e-5，初始x=1 */
