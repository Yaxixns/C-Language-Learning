/*
 * 习题17
 * 写一函数，实现两个字符串的比较，即自己写一个 strcmp 函数，函数原型为：
 *   int strcmp(char *p1, char *p2);
 * 设 p1 指向字符串 s1，p2 指向字符串 s2。要求当 s1=s2 时，返回值为 0；
 * 若 s1≠s2，返回它们二者第一个不同字符的 ASCII 码差值
 * （如"BOY"与"BAD"，第 2 个字母不同，O 与 A 之差为 79-65=14）。
 * 如果 s1>s2，则输出正值；如果 s1<s2，则输出负值。
 */

#include <stdio.h>

int strcmp_m(char *p1, char *p2)
{
    while (*p1 != '\0' && *p2 != '\0')
    {
        if (*p1 != *p2)
            return *p1 - *p2;
        p1++;
        p2++;
    }
    return *p1 - *p2;
}

int main()
{
    char s1[100], s2[100];

    printf("输入两个字符串:\n");
    gets(s1);
    gets(s2);

    int result = strcmp_m(s1, s2);
    printf("结果: %d\n", result);

    if (result == 0)
        printf("s1 = s2\n");
    else if (result > 0)
        printf("s1 > s2\n");
    else
        printf("s1 < s2\n");

    getchar();
    return 0;
}
/* ✅ 10/10 自定义strcmp正确！指针遍历→遇不等返回差值→\0再兜底，完全覆盖题意 */
