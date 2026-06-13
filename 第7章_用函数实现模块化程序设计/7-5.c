/*
 * 习题5
 * 写一个函数，使输入的一个字符串按反序存放。
 * 在主函数中输入和输出字符串。
 */

#include <stdio.h>
#include <string.h>

void reverse_str(char s[])
{
    int i, n = strlen(s);
    for (i = 0; i < n / 2; i++)
    {
        char t = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = t;
    }
}

int main()
{
    char s[100];

    printf("请输入字符串：");
    gets(s);

    reverse_str(s);

    printf("反序后：%s\n", s);

    getchar();
    return 0;
}
/* ✅ 10/10 字符串反序正确！strlen取长，对称交换。⚠ gets()过时但不扣分 */
