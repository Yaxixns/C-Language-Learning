/*
 * 习题12
 * 用指针数组处理上一题目，字符串不等长。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(char *p[], int n)
{
    int i, j;
    char *temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(*(p + j), *(p + j + 1)) > 0)
            {
                temp        = *(p + j);
                *(p + j)    = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
}

int main()
{
    char *str[10];
    char buf[100];
    int i;

    for (i = 0; i < 10; i++)
    {
        scanf("%s", buf);
        *(str + i) = (char *)malloc(strlen(buf) + 1);
        strcpy(*(str + i), buf);
    }

    sort(str, 10);

    printf("\n排序后:\n");
    for (i = 0; i < 10; i++)
        printf("%s\n", *(str + i));

    for (i = 0; i < 10; i++)
        free(*(str + i));

    getchar();
    getchar();
    return 0;
}
