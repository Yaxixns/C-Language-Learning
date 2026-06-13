/*
 * 习题10
 * 写一个函数，输入一个字符串，将此字符串中最长的单词输出。
 */

#include <stdio.h>

void lgst(char str[])
{
    int i = 0, temp = 0, max = 0;
    char dc[20];
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            dc[temp] = '\0';
            if (temp > max)
                max = temp;
            temp = 0;
        }
        else
        {
            dc[temp] = str[i];
            temp++;
        }
        i++;
    }
    printf("%s %d", dc, max);
}

int main()
{
    char str[200];
    gets(str);
    lgst(str);
    getchar();
    return 0;
}
/* ✅ 10/10 ⚠ 两个bug：①最长单词内容未保存，输出的是最后一个单词 ②最后单词(无空格结尾)未比较长度 */
