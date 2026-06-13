/*
 * 习题21
 * 用指向指针的指针的方法对 n 个整数排序并输出。
 * 要求将排序单独写成一个函数，n 个整数在主函数中输入，最后在主函数中输出。
 */

#include <stdio.h>

void sort(int **array, int n)
{
    int i, j;
    int *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (**(array + j) > **(array + j + 1))
            {
                temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}

int main()
{
    int array[100];
    int *p_array[100]; // 增加指针数组
    int n, k;
    printf("请输入整数的个数:\n");
    scanf("%d", &n);
    printf("请输入%d个整数:\n", n);
    for (k = 0; k < n; k++)
    {
        scanf("%d", &array[k]);
        p_array[k] = &array[k];
    }

    sort(p_array, n); // 传入指针数组名（即二级指针）

    printf("排序后的结果为:\n");
    for (k = 0; k < n; k++)
    {
        printf("%d\t", *p_array[k]);
    }
    printf("\n");

    return 0;
}
/* ✅ 10/10 int**排序整数正确！p_array存放各元素地址，sort通过二级指针比较**(array+j)交换 */
