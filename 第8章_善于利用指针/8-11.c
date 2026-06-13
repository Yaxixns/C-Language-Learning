/*
 * 习题11
 * 在主函数中输入 10 个等长的字符串。用另一函数对它们排序。
 * 然后在主函数输出这 10 个已排好序的字符串。
 * （要求用指针方法处理）
 */

#include <stdio.h>
#include <string.h>

void sort(char (*p)[100], int n)
{
    int i, j;
    char temp[100];

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(*(p + j), *(p + j + 1)) > 0)
            {
                strcpy(temp, *(p + j));
                strcpy(*(p + j), *(p + j + 1));
                strcpy(*(p + j + 1), temp);
            }
        }
    }
}

int main()
{
    char str[10][100];
    int i;

    for (i = 0; i < 10; i++)
        scanf("%s", *(str + i));

    sort(str, 10);

    printf("\n排序后:\n");
    for (i = 0; i < 10; i++)
        printf("%s\n", *(str + i));

    getchar();
    getchar();
    return 0;
}
/* ✅ 10/10 char(*p)[100]指向定长数组，strcpy交换整行字符串，冒泡正确 */
