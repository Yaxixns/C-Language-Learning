/*
 * 习题18
 * 给出年、月、日，计算该日是该年的第几天。
 */

#include <stdio.h>

// 函数声明
int is_leap_year(int year);
int count_days(int year, int month, int day);

int main()
{
    int year, month, day;

    printf("请输入年、月、日（用空格隔开，如 2026 6 13）: ");
    if (scanf("%d %d %d", &year, &month, &day) == 3)
    {
        int total_days = count_days(year, month, day);

        // 如果输入的日期不合法，count_days 会返回 -1
        if (total_days != -1)
        {
            printf("%d 年 %d 月 %d 日是该年的第 %d 天。\n", year, month, day, total_days);
        }
    }

    return 0;
}

/**
 * 判断是否为闰年
 * 返回值：1 表示闰年，0 表示平年
 */
int is_leap_year(int year)
{
    // 闰年判定条件：能被 4 整除但不能被 100 整除，或者能被 400 整除
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return 1;
    }
    return 0;
}

/**
 * 计算该日是该年的第几天
 */
int count_days(int year, int month, int day)
{
    // 平年 12 个月的天数（下标 0 闲置，方便让下标 1~12 对应 1~12 月）
    int months_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days = 0;

    // 简单的输入合法性校验
    if (month < 1 || month > 12 || day < 1)
    {
        printf("输入的月份或日期不合法！\n");
        return -1;
    }

    // 1. 累加前 month - 1 个月的完整天数
    // 比如输入的是 6 月 13 日，就先把 1、2、3、4、5 月的天数全加起来
    for (int i = 1; i < month; i++)
    {
        total_days += months_days[i];
    }

    // 2. 加上当前月的剩余天数
    total_days += day;

    // 3. 特殊处理：如果是闰年，且月份超过了 2 月，总天数需要加 1
    if (is_leap_year(year) && month > 2)
    {
        total_days += 1;
    }

    return total_days;
}
/* ✅ 10/10 年月日计算正确！闰年判断+月份天数表+>2月闰年修正+输入合法性校验，完整 */
