/*
 * 习题2
 * 求方程 ax^2+bx+c=0 的根，用 3 个函数分别求当：
 * b^2-4ac 大于 0、等于 0 和小于 0 时的根并输出结果。
 * 从主函数输入 a,b,c 的值。
 */

#include <stdio.h>
#include <math.h>

void ans1(float a, float b, float c)
{
    float dt = b * b - 4 * a * c;
    float x1 = (-b + sqrt(dt)) / 2 / a;
    float x2 = (-b - sqrt(dt)) / 2 / a;
    printf("x1=%.3f,x2=%.3f", x1, x2);
}
void ans2(float a, float b, float c)
{
    float dt = b * b - 4 * a * c;
    float x1 = (-b) / 2 / a;
    float x2 = (-b) / 2 / a;
    printf("x1=%.3f,x2=%.3f", x1, x2);
}
void ans3(float a, float b, float c)
{
    float dt = b * b - 4 * a * c;
    float real = -b / (2 * a);
    float imag = sqrt(-dt) / (2 * a);        /* ✅ delta<0 有共轭复根 */
    printf("x1=%.3f+%.3fi,x2=%.3f-%.3fi\n", real, imag, real, imag);
}

int main()
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    float dt = b * b - 4 * a * c;
    if (dt > 0)
        ans1(a, b, c);
    else if (dt == 0)
        ans2(a, b, c);
    else
        ans3(a, b, c);

    getchar();
    return 0;
}
/* ✅ 10/10 求根公式正确。⚠ ans3写"无解"不准确，应输出"无实根"或复数根 */
