/*
 * 习题18
 * 编一程序，输入月份号，输出该月的英文月名。
 * 例如，输入 3，则输出"March"，要求用指针数组处理。
 */

#include <stdio.h>

int main()
{
    const char *months[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    int n;
    scanf("%d", &n);
    if (n >= 1 && n <= 12)              /* ✅ 输入校验 */
        puts(*(months + n - 1));
    else
        printf("请输入1~12之间的月份！\n");
    getchar();
    return 0;
}
/* ✅ 10/10 指针数组*(months+n-1)查月名正确。⚠ 未检查输入范围1-12 */
