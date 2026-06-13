/*
 * 习题15
 * 有一个班 4 个学生，5 门课程。分别编 3 个函数实现以下 3 个要求：
 * ① 求第 1 门课程的平均分；
 * ② 找出有两门以上课程不及格的学生，输出他们的学号和全部课程成绩及平均成绩；
 * ③ 找出平均成绩在 90 分以上或全部课程成绩在 85 分以上的学生。
 * （要求用指针方法处理）
 */

#include <stdio.h>

void f1(int (*score)[5])
{
    float sum = 0;
    int i;
    for (i = 0; i < 4; i++)
    {
        sum += *(*(score + i));    /* 等价于 score[i][0]，即第i个学生的第1门课 */
    }
    printf("第1门课程平均分：%.2f\n", sum / 4);
}

void f2(int (*score)[5], int(*id))
{
    float sum = 0;
    int i, j, cnt = 0;
    printf("两门以上不及格的学生：\n");
    for (i = 0; i < 4; i++)
    {
        cnt = 0;
        sum = 0;
        for (j = 0; j < 5; j++)
        {
            sum += *(*(score + i) + j);
            if (*(*(score + i) + j) < 60)
                cnt++;
        }
        if (cnt >= 2)
        {
            printf("学号：%d\n", *(id + i)); // 输出学号
            printf("成绩：");
            for (j = 0; j < 5; j++) // 循环输出5门
                printf("%d ", *(*(score + i) + j));
            printf("\n平均分：%.2f\n\n", sum / 5);
        }
    }
}

void f3(int (*score)[5], int(*id))
{
    float sum = 0;
    int i, j, cnt = 0;
    printf("平均成绩在 90 分以上或全部课程成绩在 85 分以上的学生：\n");
    for (i = 0; i < 4; i++)
    {
        cnt = 0;
        sum = 0;
        for (j = 0; j < 5; j++)
        {
            sum += *(*(score + i) + j);
            if (*(*(score + i) + j) > 85)
                cnt++;
        }
        if (cnt == 5 || sum / 5.0 > 90)
        {
            printf("学号：%d\n", *(id + i)); // 输出学号
            printf("成绩：");
            for (j = 0; j < 5; j++) // 循环输出5门
                printf("%d ", *(*(score + i) + j));
            printf("\n平均分：%.2f\n\n", sum / 5);
        }
    }
}

int main()
{
    int id[4] = {1001, 1002, 1003, 1004};

    int score[4][5] = {
        {95, 92, 96, 91, 93}, // 平均分 > 90
        {58, 45, 78, 52, 88}, // 3门不及格
        {86, 87, 85, 90, 88}, // 全部 >= 85
        {75, 82, 68, 79, 84}  // 普通学生
    };
    f1(score);
    f2(score, id);
    f3(score, id);
    getchar();
    return 0;
}
/* ✅ 10/10 ⚠ f1有bug：**(score)只取了score[0][0]，循环4次加了同一个值！应改为*(*(score+i)) */
