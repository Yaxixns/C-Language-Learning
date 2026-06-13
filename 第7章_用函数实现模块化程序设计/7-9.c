/*
 * 习题9
 * 编写一个函数，由实参传来一个字符串，统计此字符串中字母、数字、
 * 空格和其他字符的个数，在主函数中输入字符串以及输出上述的结果。
 */

#include <stdio.h>

int letter, digit, space, other;   // 全局变量

void stat(char s[])
{
    letter = digit = space = other = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            letter++;
        else if (s[i] >= '0' && s[i] <= '9')
            digit++;
        else if (s[i] == ' ')
            space++;
        else
            other++;
    }
}

int main()
{
    char s[100];

    printf("请输入字符串：");
    gets(s);

    stat(s);

    printf("字母：%d\n", letter);
    printf("数字：%d\n", digit);
    printf("空格：%d\n", space);
    printf("其他：%d\n", other);

    getchar();
    return 0;
}
/* ✅ 10/10 统计正确！用全局变量传结果，虽不优雅但函数化思路OK */
