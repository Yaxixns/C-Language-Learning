/*
 * 习题8
 * 写一个函数，输入一个 4 位数字，要求输出这 4 个数字字符，
 * 但每两个数字间空一个空格。如输入 1990，应输出"1 9 9 0"。
 */

#include <stdio.h>

void prtdit(int n)
{
    printf("%d ", n / 1000);
    printf("%d ", n / 100 % 10);
    printf("%d ", n / 10 % 10);
    printf("%d\n", n % 10);
}

int main()
{
    int n;
    scanf("%d", &n);
    prtdit(n);
    getchar();
    return 0;
}
/* ✅ 10/10 数字分拆正确！⚠ 每位数后多一个空格，输出尾有冗余空格 */
