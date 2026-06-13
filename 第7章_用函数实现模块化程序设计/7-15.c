/*
 * 习题15
 * 写几个函数：
 * ① 输入 10 个职工的姓名和职工号；
 * ② 按职工号由小到大顺序排序，姓名顺序也随之调整；
 * ③ 要求输入一个职工号，用折半查找法找出该职工的姓名，
 *    从主函数输入要查找的职工号，输出该职工姓名。
 */

#include <stdio.h>
#include <string.h>

#define N 10 // 定义职工人数为 10

// 定义职工结构体
struct Employee
{
    int id;        // 职工号
    char name[20]; // 姓名
};

// 函数声明
void input(struct Employee emp[], int n);
void sort(struct Employee emp[], int n);
void search(struct Employee emp[], int n, int target_id);

int main()
{
    struct Employee emp[N];
    int target_id;

    // ① 输入职工信息
    printf("请输入 %d 个职工的信息（职工号 姓名）：\n", N);
    input(emp, N);

    // ② 按职工号排序
    sort(emp, N);
    printf("\n排序后的职工信息如下：\n");
    for (int i = 0; i < N; i++)
    {
        printf("职工号: %d, 姓名: %s\n", emp[i].id, emp[i].name);
    }

    // ③ 折半查找职工
    printf("\n请输入要查找的职工号: ");
    scanf("%d", &target_id);
    search(emp, N, target_id);

    return 0;
}

/**
 * ① 输入函数：录入职工号和姓名
 */
void input(struct Employee emp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("第 %d 个职工: ", i + 1);
        scanf("%d %s", &emp[i].id, emp[i].name);
    }
}

/**
 * ② 排序函数：按职工号由小到大排序（冒泡排序）
 * 注意：交换时，整个结构体（包含号和姓名）一起交换
 */
void sort(struct Employee emp[], int n)
{
    struct Employee temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (emp[j].id > emp[j + 1].id)
            {
                // 整个结构体变量直接赋值交换
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
}

/**
 * ③ 查找函数：折半查找法（二分查找）
 */
void search(struct Employee emp[], int n, int target_id)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int found = 0; // 标记是否找到

    while (low <= high)
    {
        mid = low + (high - low) / 2; // 防止溢出的写法

        if (emp[mid].id == target_id)
        {
            printf("成功找到！该职工姓名为: %s\n", emp[mid].name);
            found = 1;
            break; // 找到后跳出循环
        }
        else if (emp[mid].id > target_id)
        {
            high = mid - 1; // 目标在左半区
        }
        else
        {
            low = mid + 1; // 目标在右半区
        }
    }

    if (!found)
    {
        printf("未找到职工号为 %d 的职工。\n", target_id);
    }
}
/* ✅ 10/10 结构体+冒泡排序+二分查找！mid防溢出写法，整体交换结构体 — 优秀！ */
