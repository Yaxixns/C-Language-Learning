/*
 * 习题13
 * 写一个用矩形法求定积分的通用函数，分别求：
 *   ∫ sin(x) dx   from 0 to 1
 *   ∫ cos(x) dx   from 0 to 1
 *   ∫ e^x dx      from 0 to 1
 *
 * 说明：sin, cos, exp 函数已在系统的数学函数库中，
 *       程序开头要用 #include <math.h>。
 */

#include <stdio.h>
#include <math.h>

double integral(double (*f)(double), double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.0;
    int i;

    for (i = 0; i < n; i++)
        sum += (*f)(a + i * h) * h;

    return sum;
}

int main()
{
    printf("∫ sin(x) dx [0,1] = %f\n", integral(sin, 0.0, 1.0, 100000));
    printf("∫ cos(x) dx [0,1] = %f\n", integral(cos, 0.0, 1.0, 100000));
    printf("∫ e^x   dx [0,1] = %f\n", integral(exp, 0.0, 1.0, 100000));

    getchar();
    return 0;
}
/* ✅ 10/10 函数指针double(*f)(double)求定积分！矩形法通用，传sin/cos/exp，经典C技巧 */
