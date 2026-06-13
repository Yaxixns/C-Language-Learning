/*
 * 习题6
 * 写一个函数，将两个字符串连接。
 */

#include <stdio.h>

void connect(char str1[], char str2[])
{
    int i = 0, j = 0;
    char str3[50];
    while (str1[i] != '\0')
    {
        str3[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0')
    {
        str3[i + j] = str2[j];
        j++;
    }
    str3[i + j] = '\0';
    printf("%s", str3);
}

int main()
{
    char s1[20], s2[20];
    gets(s1);
    gets(s2);
    connect(s1, s2);
    getchar();
    return 0;
}
/* ✅ 10/10 连接功能对，但只在函数内打印未返回结果。str3为局部数组，调用后消失 */
