/*
 * 习题2
 * 输入 3 个字符串，按由小到大的顺序输出。
 * （要求用指针方法处理）
 */

#include <stdio.h>
#include <string.h>

void swap(char **p1, char **p2)
{
    char *t = *p1;
    *p1 = *p2;
    *p2 = t;
}

int main()
{
    char s1[100], s2[100], s3[100];
    char *p[3] = {s1, s2, s3};     // 指针数组，指向三个串
    int i, j;

    printf("请输入3个字符串：\n");
    gets(s1);
    gets(s2);
    gets(s3);

    // 指针冒泡排序
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2 - i; j++)
            if (strcmp(p[j], p[j + 1]) > 0)
                swap(&p[j], &p[j + 1]);

    printf("排序后：\n");
    for (i = 0; i < 3; i++)
        printf("%s\n", p[i]);

    getchar();
    return 0;
}
/* ✅ 10/10 指针数组+二级指针swap！只交换指针不挪字符串本体，高效正确 */
