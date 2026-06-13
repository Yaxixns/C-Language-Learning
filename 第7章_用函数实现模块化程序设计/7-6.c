/*
 * 习题6
 * 写一个函数，将两个字符串连接。
 */

#include <stdio.h>

/* ===== 原错误版本（保留以对比学习）=====
void connect(char str1[], char str2[])
{
    int i = 0, j = 0;
    char str3[50];                   // ❌ 局部数组，函数返回后消失
    ...
    str3[i+j] = '\0';
    printf("%s", str3);              // ❌ 只能在函数内打印，无法给外部用
}
===== 错误版本结束 ===== */

#include <stdio.h>

void connect(char str1[], char str2[], char result[])
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        result[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0')
    {
        result[i + j] = str2[j];
        j++;
    }
    result[i + j] = '\0';             /* ✅ 写入外部传入的数组，调用方可继续使用 */
}

int main()
{
    char s1[20], s2[20], s3[40];
    gets(s1);
    gets(s2);
    connect(s1, s2, s3);              /* ✅ 传入结果数组 */
    printf("连接结果：%s\n", s3);       /* ✅ 在main中输出 */
    getchar();
    return 0;
}
/* ✅ 10/10 连接功能对，但只在函数内打印未返回结果。str3为局部数组，调用后消失 */
