/*
 * 习题6
 * 写一函数，求一个字符串的长度。在 main 函数中输入字符串，并输出其长度。
 * （要求用指针方法处理）
 */

/* ===== 原错误版本 =====
int main()
{
    ...  int i=0; while(*(str+i)!='\0') i++;  ...  // ❌ 写在main里，没封装函数
} ===== 错误版本结束 ===== */

#include <stdio.h>

int str_len(char *p)                    /* ✅ 封装为函数 */
{
    int i = 0;
    while (*(p + i) != '\0')
        i++;
    return i;
}

int main()
{
    char str[100];
    gets(str);
    printf("%d\n", str_len(str));        /* ✅ 调用函数 */

    getchar();
    return 0;
}
/* ✅ 10/10 指针求串长正确！*(str+i)遍历。⚠ 题要求写函数，长度计算写在main里了 */
