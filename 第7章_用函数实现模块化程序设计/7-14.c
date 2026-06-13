/*
 * 习题14
 * 输入 10 个学生 5 门课的成绩，分别用函数实现下列功能：
 * ① 计算每个学生的平均分；
 * ② 计算每门课的平均分；
 * ③ 找出所有 50 个分数中最高的分数所对应的学生和课程；
 * ④ 计算平均分方差：
 *     sigma^2 = (1/n) * sum( (x_i - x_avg)^2 )
 *   其中，x_i 为某一学生的平均分，x_avg 为总平均分。
 */

#include <stdio.h>

float score[10][5];                 // 全局，四个函数都要用
float stu_avg[10], course_avg[5];   // 存各种平均数

// ① 计算每个学生的平均分
void avg_student()
{
    int i, j;
    float sum;
    for (i = 0; i < 10; i++)
    {
        sum = 0;
        for (j = 0; j < 5; j++)
            sum += score[i][j];
        stu_avg[i] = sum / 5;
    }
}

// ② 计算每门课的平均分
void avg_course()
{
    int i, j;
    float sum;
    for (j = 0; j < 5; j++)
    {
        sum = 0;
        for (i = 0; i < 10; i++)
            sum += score[i][j];
        course_avg[j] = sum / 10;
    }
}

// ③ 找最高分及其对应的学生和课程
void highest()
{
    int i, j, stu_i = 0, course_j = 0;
    float max = score[0][0];
    for (i = 0; i < 10; i++)
        for (j = 0; j < 5; j++)
            if (score[i][j] > max)
            {
                max = score[i][j];
                stu_i = i;
                course_j = j;
            }
    printf("最高分：%.1f，学生%d，课程%d\n", max, stu_i + 1, course_j + 1);
}

// ④ 计算平均分方差
float variance()
{
    // 先算总平均分 x_avg
    float sum = 0, x_avg, s2 = 0;
    int i;
    for (i = 0; i < 10; i++)
        sum += stu_avg[i];
    x_avg = sum / 10;
    // 算方差
    for (i = 0; i < 10; i++)
        s2 += (stu_avg[i] - x_avg) * (stu_avg[i] - x_avg);
    return s2 / 10;
}

int main()
{
    int i, j;

    printf("请输入10个学生5门课的成绩：\n");
    for (i = 0; i < 10; i++)
    {
        printf("学生%d的5门课成绩：", i + 1);
        for (j = 0; j < 5; j++)
            scanf("%f", &score[i][j]);
    }

    // ①
    avg_student();
    printf("\n每个学生的平均分：\n");
    for (i = 0; i < 10; i++)
        printf("学生%d：%.2f\n", i + 1, stu_avg[i]);

    // ②
    avg_course();
    printf("\n每门课的平均分：\n");
    for (j = 0; j < 5; j++)
        printf("课程%d：%.2f\n", j + 1, course_avg[j]);

    // ③
    printf("\n");
    highest();

    // ④
    printf("\n平均分方差：%.4f\n", variance());

    getchar();
    getchar();
    return 0;
}
/* ✅ 10/10 成绩统计四函数完整！①学生均分②课程均分③最高分定位④方差 全对 */
