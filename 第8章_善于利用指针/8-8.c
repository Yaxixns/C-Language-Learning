/*
 * 习题8
 * 输入一行文字，找出其中大写字母、小写字母、空格、数字以及其他字符各有多少。
 * （要求用指针方法处理）
 */

#include <stdio.h>

int main()
{
    char str[100];
    gets(str);
    int i = 0, up = 0, down = 0, space = 0, dig = 0, other = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) >= 'A' && *(str + i) <= 'Z')
            up++;
        else if (*(str + i) >= 'a' && *(str + i) <= 'z')
            down++;
        else if (*(str + i) == ' ')
            space++;
        else if (*(str + i) >= '0' && *(str + i) <= '9')
            dig++;
        else
            other++;
        i++;
    }
    printf("大写字母：%d\n", up);
    printf("小写字母：%d\n", down);
    printf("空格：%d\n", space);
    printf("数字：%d\n", dig);
    printf("其他：%d\n", other);

    getchar();
    return 0;
}
/* ✅ 10/10 指针统计字符正确！*(str+i)遍历，五类分别计数。gets不含\n所以other正确 */
