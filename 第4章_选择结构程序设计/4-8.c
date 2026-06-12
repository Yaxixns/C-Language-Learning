/*
 * 习题8
 * 给出一个百分制成绩，要求输出成绩等级'A'、'B'、'C'、'D'、'E'。
 * 90 分以上为'A'，80～89 分为'B'，70～79 分为'C'，
 * 60～69 分为'D'，60 分以下为'E'。
 */

#include <stdio.h>

int main()
{
    int score;
    scanf("%d", &score);
    int x = score / 10;
    switch (x)
    {
    case 10:
        printf("等级为A\n");
        break;
    case 9:
        printf("等级为A\n");
        break;
    case 8:
        printf("等级为B\n");
        break;
    case 7:
        printf("等级为C\n");
        break;
    case 6:
        printf("等级为D\n");
        break;
    default:
        printf("等级为E\n");
        break;
    }

    getchar();
    return 0;
}
/* ────────────────────────────────────────
 * 📝 批改评语：✅ 非常巧妙！10/10
 *
 * ① 用 score/10 把百分制映射到 0~10，配合 switch —— 经典操作！
 * ② case 10 和 case 9 合并输出 A（穿透利用得当）。
 * ③ 边界处理全部正确：
 *    100→10→A ✓  90→9→A ✓  89→8→B ✓
 *    79→7→C ✓  69→6→D ✓  59→5→E ✓
 * ④ default 覆盖所有 <60 的情况。
 *
 * 💡 这是第四章最漂亮的代码之一。switch+整除是成绩分级的经典解法。
 * ──────────────────────────────────────── */
