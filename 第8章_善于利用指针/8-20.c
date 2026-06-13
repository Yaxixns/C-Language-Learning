/*
 * 习题20
 * 用指向指针的指针的方法对 5 个字符串排序并输出。
 */

#include <stdio.h>
#include <string.h>

void sort(char **p, int n)
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
    char str[5][100];
    char *p[5];
    char **pp;
    int i;

    for (i = 0; i < 5; i++)
    {
        scanf("%s", str[i]);
        *(p + i) = *(str + i);
    }

    pp = p;
    sort(pp, 5);

    printf("\n排序后:\n");
    for (i = 0; i < 5; i++)
        printf("%s\n", *(pp + i));

    getchar();
    getchar();
    return 0;
}
/* ✅ 10/10 char**指向指针数组，sort交换指针不挪串，pp=p传递二级指针正确 */
