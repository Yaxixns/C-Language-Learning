/*
 * 习题16
 * 输入一个字符串，内有数字和非数字字符，例如：
 *   A123x456 17960? 302tab5876
 * 将其连续的数字作为一个整数，依次存放到一数组 a 中。
 * 例如，123 放在 a[0]，456 放在 a[1]……
 * 统计共有多少个整数，并输出这些数。
 * （要求用指针方法处理）
 */

#include <stdio.h>

int main()
{
    char str[100];
    int a[100];
    gets(str);

    int i = 0, temp = 0, cnt = 0, in_num = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) >= '0' && *(str + i) <= '9')
        {
            temp = temp * 10 + (*(str + i) - '0'); /* ⚠️ 别忘了 -'0' */
            in_num = 1;
        }
        else
        {
            if (in_num) /* ⚠️ 用标志位判断 */
            {
                *(a + cnt) = temp;
                temp = 0;
                cnt++;
                in_num = 0;
            }
        }
        i++;
    }
    if (in_num) /* ⚠️ 收尾 */
    {
        *(a + cnt) = temp;
        cnt++;
    }

    printf("共 %d 个整数:\n", cnt);
    for (i = 0; i < cnt; i++)
        printf("%d ", *(a + i));

    getchar();
    return 0;
}
/* ✅ 10/10 提取整数正确！temp=temp*10+digit累积，in_num标志位+末尾收尾，注释清晰 */
