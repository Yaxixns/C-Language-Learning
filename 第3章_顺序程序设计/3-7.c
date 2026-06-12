/*
 * 习题7
 * 设圆半径 r=1.5，圆柱高 h=3，求圆周长、圆面积、圆球表面积、圆球体积、
 * 圆柱体积。用 scanf 输入数据，输出计算结果，输出时要求有文字说明，
 * 取小数点后 2 位数字。请编程序。
 */

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main()
{
    float r = 1.5, h = 3;
    float zc, mj, bmj, qtj, ztj;
    float pi = 3.1415926;

    zc = 2 * pi * r;
    mj = pi * r * r;
    bmj = 4 * pi * r * r;
    qtj = 4 / 3.0 * pi * r * r * r;
    ztj = pi * r * r * h;
    printf("圆周长：%.2f\n", zc);
    printf("圆面积：%.2f\n", mj);
    printf("圆球表面积：%.2f\n", bmj);
    printf("圆球体积：%.2f\n", qtj);
    printf("圆柱体积：%.2f\n", ztj);

    return 0;
}

/* ────────────────────────────────────────
 * 📝 批改评语：✅ 公式全对！8/10
 *
 * ① 五个几何公式全部正确：
 *    圆周长 2πr ✓、圆面积 πr² ✓、球表面积 4πr² ✓
 *    球体积 4/3 πr³ ✓（用 4/3.0 避免了整数除法坑！）
 *    圆柱体积 πr²h ✓
 * ② %.2f 控制两位小数 ✓
 *
 * ⚠️ 扣分原因：题目明确要求"用 scanf 输入数据"，
 *    但你直接赋值了 r=1.5, h=3。
 *    虽然题目给了这两个值，但考试时如果明确要求 scanf，
 *    就必须用 scanf 读取，否则扣分。
 *
 * 💡 正确做法：
 *    float r, h;
 *    scanf("%f %f", &r, &h);
 * ──────────────────────────────────────── */
