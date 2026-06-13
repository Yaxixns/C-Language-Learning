/*
 * 习题11
 * 输出以下图案：
 *   * * * * *
 *     * * * * *
 *       * * * * *
 *         * * * * *
 *           * * * * *
 */

#include <stdio.h>

int main()
{
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("  ");
        }
        printf("* * * * *\n");
    }

    getchar();
    return 0;
}
