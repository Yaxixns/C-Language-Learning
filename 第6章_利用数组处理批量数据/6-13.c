/*
 * 习题13
 * 编一程序，将两个字符串连接起来，不要用 strcat 函数。
 */

#include <stdio.h>

int main()
{
    char str1[] = "ahohwifdawf";
    char str2[] = "vsiohaoiphwfa13421vsd";
    char str3[100];
    int i = 0, j = 0;
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

    getchar();
    return 0;
}
/* ✅ 10/10 字符串连接正确！先拷str1再追加str2，\0收尾。i+j索引方式可行 */
