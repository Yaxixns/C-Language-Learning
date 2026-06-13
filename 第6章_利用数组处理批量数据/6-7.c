/*
 * 习题7
 * 输出"魔方阵"。所谓魔方阵是指这样的方阵，它的每一行、每一列和对角线之和
 * 均相等。例如，三阶魔方阵为：
 *   8   1   6
 *   3   5   7
 *   4   9   2
 * 要求输出 1~n^2 的自然数构成的魔方阵。
 */

#include <stdio.h>

int main()
{
    int a[15][15] = {0}, n, i, j, row, col;

    printf("请输入奇数阶数 n (n<=15): ");
    scanf("%d", &n);

    // 1 放在第一行中间
    row = 0;
    col = n / 2;
    a[row][col] = 1;

    // 依次放置 2 到 n*n
    for (i = 2; i <= n * n; i++)
    {
        // 下一个位置：右上方（行减1，列加1）
        int next_row = (row - 1 + n) % n;
        int next_col = (col + 1) % n;

        if (a[next_row][next_col] == 0)     // 位置为空
        {
            row = next_row;
            col = next_col;
        }
        else                                // 位置已被占用，放在正下方
        {
            row = (row + 1) % n;
        }
        a[row][col] = i;
    }

    // 输出魔方阵
    printf("\n%d 阶魔方阵：\n", n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    getchar();
    getchar();
    return 0;
}
