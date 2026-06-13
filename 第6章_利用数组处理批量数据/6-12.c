/*
 * 习题12
 * 有一行电文，已按下面规律译成密码：
 *   A -> Z    a -> z
 *   B -> Y    b -> y
 *   C -> X    c -> x
 *   :  :      :  :
 * 即第 1 个字母变成第 26 个字母，第 i 个字母变成第 (26 - i + 1) 个字母，
 * 非字母字符不变。要求编程将密码译回原文，并输出密码和原文。
 */

#include <stdio.h>

int main()
{
    char str[100];
    printf("请输入密码：");
    gets(str);
    printf("密码：%s\n", str); // 先输出密码

    printf("原文：");
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            printf("%c", 'A' + 'Z' - str[i]);
        else if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", 'a' + 'z' - str[i]);
        else
            printf("%c", str[i]);
    }
    printf("\n");

    getchar();
    return 0;
}
