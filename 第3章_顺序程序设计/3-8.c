/*
 * 习题8
 * 编程序，用 getchar 函数读入两个字符给 c1 和 c2，然后分别用 putchar 函数
 * 和 printf 函数输出这两个字符。思考以下问题：
 * （1）变量 c1 和 c2 应定义为字符型、整型还是二者皆可？
 * （2）要求输出 c1 和 c2 值的 ASCII 码，应如何处理？用 putchar 函数还是 printf 函数？
 * （3）整型变量与字符变量是否在任何情况下都可以互相代替？如：
 *       char c1, c2;
 *     与
 *       int c1, c2;
 *     是否无条件地等价？
 */

#include <stdio.h>

int main()
{
    char c1, c2;
    printf("请输入两个字符：");
    c1 = getchar();
    c2 = getchar();

    printf("用putchar输出：");
    putchar(c1);
    putchar(c2);
    putchar('\n');

    printf("用printf输出：%c%c\n", c1, c2);
    printf("ASCII码：c1=%d, c2=%d\n", c1, c2);

    return 0;
}

/*
    (1) 变量 c1 和 c2 应定义为字符型、整型还是二者皆可？
    答：定义为字符型(char)或整型(int)均可。
    因为 getchar() 的返回值类型是 int（它可以返回 -1/EOF 表示读取结束），
    但如果仅用于存储普通字符（0~255），char 和 int 都能正确保存。
    严谨的做法是用 int 类型接收，这样可以判断 getchar() 是否返回了 EOF。

    (2) 要求输出 c1 和 c2 值的 ASCII 码，应如何处理？用 putchar 还是 printf？
    答：用 printf 函数配合 %d 格式符即可输出 ASCII 码（十进制整数）。
    例如 printf("%d", c1); 输出的是 c1 对应的 ASCII 码数值。
    putchar 只能输出字符本身，不能输出数值。

    (3) 整型变量与字符变量是否在任何情况下都可以互相代替？
    答：不可以无条件等价。主要区别：
    - char 通常占 1 字节（范围 -128~127 或 0~255），int 通常占 4 字节
    - 若赋值超出 char 范围（如 300），char 会溢出，int 不会
    - getchar() 返回 EOF(-1) 时，char 类型无法正确区分 EOF 和字符 255
    - char 更省内存，适合存储大量字符数据；int 更安全，适合接收 getchar 返回值
*/
/* ────────────────────────────────────────
 * 📝 批改评语：✅ 程序+概念都正确！10/10
 *
 * 程序部分：
 * ① getchar/putchar 使用正确
 * ② printf 用 %c 输出字符、%d 输出ASCII码，双模式到位
 *
 * 概念部分：
 * ① "char或int均可，但int更严谨（可判断EOF）" — 考点命中！
 * ② "用printf配合%d输出ASCII码" — 正确，putchar只能输出字符
 * ③ "不可无条件等价" + 三个理由（范围/EOF/内存）— 完整！
 *
 * 这是第三章答得最全面的题，概念和代码都无可挑剔。
 * ──────────────────────────────────────── */
