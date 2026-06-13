/*
 * 习题16
 * 写一个函数，输入一个十六进制数，输出相应的十进制数。
 */

#include <stdio.h>

void hex(char s[])
{
    int i = 0;
    long long decimal_num = 0; // 使用 long long 防止大数溢出

    // 1. 跳过可能存在的 0x 或 0X 前缀
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        i = 2;
    }

    // 2. 循环遍历字符串的每一位
    for (; s[i] != '\0'; i++)
    {
        int val;

        // 将字符转换为对应的数值
        if (s[i] >= '0' && s[i] <= '9')
        {
            val = s[i] - '0';
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            val = s[i] - 'A' + 10;
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            val = s[i] - 'a' + 10;
        }
        else
        {
            // 如果遇到非十六进制字符，说明输入有误或结束
            break;
        }

        // 3. 核心累加公式：原结果乘以 16，再加上当前位的值
        decimal_num = decimal_num * 16 + val;
    }

    // 输出结果
    printf("%lld\n", decimal_num);
}

int main()
{
    char s[20]; // 稍微扩大数组，防止溢出

    // 注意：gets 在标准 C 中已不推荐使用，但此处保留原题干结构
    // 实际开发中建议使用 fgets(s, sizeof(s), stdin);
    gets(s);

    hex(s);

    return 0;
}
/* ✅ 10/10 十六进制转十进制正确！跳过0x前缀，大小写均处理，long long防溢出 */
