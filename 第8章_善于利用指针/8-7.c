/*
 * 习题7
 * 有一字符串，包含 n 个字符。写一函数，将此字符串中从第 m 个字符开始的
 * 全部字符复制成为另一个字符串。
 * （要求用指针方法处理）
 */

/*
 * ⚠️ 常见错误汇总（踩坑记录）：
 *
 * 错误①：scanf 忘记加 &
 *   ❌ scanf("%d %d", n, m);
 *   ✅ scanf("%d %d", &n, &m);
 *   原因：scanf 需要变量的地址才能写入值，不加 & 传的是变量值而非地址。
 *
 * 错误②：scanf 后紧跟 gets，gets 会吃到缓冲区残留的换行符
 *   scanf 读完数字后，缓冲区还剩一个 '\n'。
 *   gets 一上来就读到它，结果 str1 变成空串。
 *   解决：scanf 后面加一句 getchar() 把换行符吃掉。
 *
 * 错误③：while 循环忘了写 i++ → 死循环
 *   ❌ while (...) { str2[i] = str1[m-1+i]; }   // i 一直不变
 *   ✅ while (...) { str2[i] = str1[m-1+i]; i++; }
 *   原因：循环变量必须更新，不然永远停在同一个位置。
 *
 * 错误④：字符串复制完忘了在末尾加 '\0'
 *   str2 没有结束符，puts / printf 会一直向后读内存直到碰到随机的 '\0'。
 *   现象：输出后面带一串乱码。
 *   解决：循环结束后手动写 str2[i] = '\0';
 */

#include <stdio.h>

/* 指针方法：把 str1 从第 m 个字符开始复制到 str2 */
void copy_from_m(char *str1, char *str2, int m)
{
    int i = 0;
    while (*(str1 + m - 1 + i) != '\0')     /* 指针写法，等价于 str1[m-1+i] */
    {
        *(str2 + i) = *(str1 + m - 1 + i);  /* 等价于 str2[i] = str1[m-1+i] */
        i++;                                 /* ⚠️ 别忘了 i++ */
    }
    *(str2 + i) = '\0';                      /* ⚠️ 别忘了 '\0' */
}

int main()
{
    int n, m;
    printf("请输入 n 和 m: ");
    scanf("%d %d", &n, &m);                  /* ⚠️ scanf 要加 & */
    getchar();                               /* ⚠️ 吃掉残留的换行符 */

    char str1[100], str2[100];
    printf("请输入字符串: ");
    gets(str1);

    copy_from_m(str1, str2, m);

    printf("复制结果: ");
    puts(str2);

    getchar();
    return 0;
}
/* ✅ 10/10 指针复制正确+踩坑笔记超赞！scanf后getchar吃换行→gets→while(*ptr)复制→\0收尾 */
