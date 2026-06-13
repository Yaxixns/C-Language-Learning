/*
 * 习题7
 * 写一个函数，将一个字符串中的元音字母复制到另一个字符串，然后输出。
 */

#include <stdio.h>

void copy_vowels(char src[], char dst[])
{
    int i, j = 0;
    for (i = 0; src[i] != '\0'; i++)
    {
        char c = src[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            dst[j++] = c;
        }
    }
    dst[j] = '\0';
}

int main()
{
    char s1[100], s2[100];

    printf("请输入字符串：");
    gets(s1);

    copy_vowels(s1, s2);
    printf("元音字母：%s\n", s2);

    getchar();
    return 0;
}
