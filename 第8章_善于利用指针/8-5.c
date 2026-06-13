/*
 * 习题5
 * 有 n 个人围成一圈，顺序排号。从第 1 个人开始报数（从 1 到 3 报数），
 * 凡报到 3 的人退出圈子，问最后留下的是原来第几号的那位。
 * （要求用指针方法处理）
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        *(a + i) = 1;

    int left = n;
    int count = 0;
    int i = 0;

    while (left > 1)
    {
        if (*(a + i))
        {
            count++;

            if (count == 3)
            {
                *(a + i) = 0;
                left--;
                count = 0;
            }
        }

        i = (i + 1) % n;
    }

    for (i = 0; i < n; i++)
    {
        if (*(a + i))
        {
            printf("最后留下的是原来的第%d号\n", i + 1);
            break;
        }
    }

    free(a);
    return 0;
}
