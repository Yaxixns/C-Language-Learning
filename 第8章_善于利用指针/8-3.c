/*
 * 习题3
 * 输入 10 个整数，将其中的最小的数与第一个数对换，把最大的数与最后一个数对换。
 * 写 3 个函数：① 输入 10 个数；② 进行处理；③ 输出 10 个数。
 * （要求用指针方法处理）
 */

#include <stdio.h>

#define N 10

void input(int *arr, int n);
void process(int *arr, int n);
void output(int *arr, int n);

int main()
{
    int arr[N];

    input(arr, N);
    process(arr, N);
    output(arr, N);

    return 0;
}

void input(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
}

void process(int *arr, int n)
{
    int *min_ptr = arr;
    int *max_ptr = arr;
    int temp;

    for (int i = 1; i < n; i++)
    {
        if (*(arr + i) < *min_ptr)
        {
            min_ptr = arr + i;
        }
        if (*(arr + i) > *max_ptr)
        {
            max_ptr = arr + i;
        }
    }

    // 换最小值
    temp = *arr;
    *arr = *min_ptr;
    *min_ptr = temp;

    // 防止最大值原本在第一个位置，被上一轮对换顶走
    if (max_ptr == arr)
    {
        max_ptr = min_ptr;
    }

    // 换最大值
    temp = *(arr + n - 1);
    *(arr + n - 1) = *max_ptr;
    *max_ptr = temp;
}

void output(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
/* ✅ 10/10 三函数指针运算完整！关键：max在arr[0]时防覆盖处理(max_ptr==arr→max_ptr=min_ptr) */
