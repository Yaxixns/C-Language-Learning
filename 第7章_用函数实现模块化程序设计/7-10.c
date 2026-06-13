/*
 * 习题10
 * 写一个函数，输入一个字符串，将此字符串中最长的单词输出。
 */

/* ===== 原错误版本（保留以对比学习）=====
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
                max = temp;          // ❌ 只记了长度，没记内容
            temp = 0;
        }
        else
        {
            dc[temp] = str[i];       // ❌ dc存的是当前单词，会被下一个覆盖
            temp++;
        }
        i++;
    }                                // ❌ 最后一个单词（无空格结尾）没比较
    printf("%s %d", dc, max);        // ❌ dc是最后一个单词，不是最长的
}
===== 错误版本结束 ===== */

#include <stdio.h>
#include <string.h>

void lgst(char str[])
{
    int i = 0, start = 0, max_start = 0, max_len = 0;
    int len = strlen(str);

    while (i <= len)
    {
        if (str[i] == ' ' || str[i] == '\0')    /* ✅ 空格或结尾都处理 */
        {
            int word_len = i - start;
            if (word_len > max_len)
            {
                max_len = word_len;
                max_start = start;               /* ✅ 记录最长单词的起始位置 */
            }
            start = i + 1;                       /* 下一个单词的起始 */
        }
        i++;
    }

    printf("最长单词：");
    for (i = 0; i < max_len; i++)
        putchar(str[max_start + i]);             /* ✅ 输出真正的长单词 */
    printf(" (长度=%d)\n", max_len);
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
