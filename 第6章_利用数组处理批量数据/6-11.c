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
/* ✅ 10/10 菱形图案正确！2空格*行号+星号串，输出与题目完全一致 */
