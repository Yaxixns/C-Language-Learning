/*
 * 习题3
 * 写一个判断素数的函数，在主函数输入一个整数，输出是否为素数的信息。
 */

#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

int main()
{
    int n;
    printf("请输入一个整数：");
    scanf("%d", &n);

    if (is_prime(n))
        printf("%d 是素数\n", n);
    else
        printf("%d 不是素数\n", n);

    getchar();
    getchar();
    return 0;
}
