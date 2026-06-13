/*
 * 习题6
 * 写一函数，求一个字符串的长度。在 main 函数中输入字符串，并输出其长度。
 * （要求用指针方法处理）
 */

#include <stdio.h>

int main()
{
    char str[100];
    gets(str);
    int i = 0;
    while (*(str + i) != '\0')
    {
        i++;
    }
    printf("%d", i);

    getchar();
    return 0;
}
