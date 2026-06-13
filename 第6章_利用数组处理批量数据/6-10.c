/*
 * 习题10
 * 有一篇文章，共有 3 行文字，每行有 80 个字符。要求分别统计出其中英文
 * 大写字母、小写字母、数字、空格以及其他字符的个数。
 */

#include <stdio.h>

int main()
{
    char text[3][81];    // 每行留一个'\0'的位置
    int i, j;
    int upper = 0, lower = 0, digit = 0, space = 0, other = 0;

    printf("请输入3行文字，每行不超过80个字符：\n");
    for (i = 0; i < 3; i++)
        gets(text[i]);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; text[i][j] != '\0'; j++)
        {
            if (text[i][j] >= 'A' && text[i][j] <= 'Z')
                upper++;
            else if (text[i][j] >= 'a' && text[i][j] <= 'z')
                lower++;
            else if (text[i][j] >= '0' && text[i][j] <= '9')
                digit++;
            else if (text[i][j] == ' ')
                space++;
            else
                other++;
        }
    }

    printf("\n大写字母：%d\n", upper);
    printf("小写字母：%d\n", lower);
    printf("数字：%d\n", digit);
    printf("空格：%d\n", space);
    printf("其他字符：%d\n", other);

    getchar();
    return 0;
}
/* ✅ 10/10 统计正确。⚠ gets()已过时，但教材仍用。注意gets()不含\n所以不会多计other */
