/*
 * 习题1
 * 写两个函数，分别求两个整数的最大公约数和最小公倍数，
 * 用主函数调用这两个函数，并输出结果。两个整数由键盘输入。
 */

#include <stdio.h>

// 最大公约数（辗转相除法）
int gcd(int a, int b)
{
    int t;
    while (b != 0)
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// 最小公倍数
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b;
    printf("请输入两个整数：");
    scanf("%d%d", &a, &b);

    printf("最大公约数：%d\n", gcd(a, b));
    printf("最小公倍数：%d\n", lcm(a, b));

    getchar();
    getchar();
    return 0;
}
/* ✅ 10/10 GCD辗转相除+LCM=a*b/gcd，封装正确，调用清晰 */
