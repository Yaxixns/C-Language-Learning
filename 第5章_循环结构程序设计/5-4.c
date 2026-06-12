/*
 * 习题4
 * 输入一行字符，分别统计出其中英文字母、空格、数字和其他字符的个数。
 */

#include <stdio.h>

int main()
{
    int letter = 0, space = 0, digtal = 0, other = 0;
    char str[50];
    fgets(str, 50, stdin);
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            letter++;
        else if (str[i] == ' ')
            space++;
        else if (str[i] >= '0' && str[i] <= '9')
            digtal++;
        else
            other++;
        i++;
    }

    printf("%d %d %d %d\n", letter, space, digtal, other);
    getchar();
    return 0;
}
/* ────────────────────────────────────────
 * 📝 批改评语：⚠️ 基本正确，2个小问题 7/10
 *
 * ① 用 fgets 读整行 — 正确，能读空格
 * ② 字母/空格/数字判断逻辑正确（&&优先级高于||）
 *
 * ⚠️ 问题1：digtal → digit（拼写错误，不影响运行）
 * ⚠️ 问题2：fgets 会把换行符 \n 也读进字符串，然后被归入 other，
 *    导致 other 多计1。应加判断跳过 \n 或循环条件改为
 *    while(str[i]!='\0' && str[i]!='\n')
 * ──────────────────────────────────────── */
