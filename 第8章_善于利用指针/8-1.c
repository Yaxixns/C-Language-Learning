/*
 * 习题1
 * 输入 3 个整数，按由小到大的顺序输出。
 * （要求用指针方法处理）
 */

#include <stdio.h>

void swap(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int a, b, c;
    // 定义三个指针，分别指向变量 a, b, c
    int *p_a = &a;
    int *p_b = &b;
    int *p_c = &c;

    printf("请输入 3 个整数（用空格隔开）: ");
    if (scanf("%d %d %d", p_a, p_b, p_c) == 3)
    { // 注意：因为 p_a 本身就是地址，所以不需要加 &

        // 1. 如果 a > b，交换 a 和 b 的值
        if (*p_a > *p_b)
        {
            swap(p_a, p_b);
        }

        // 2. 如果 a > c，交换 a 和 c 的值
        if (*p_a > *p_c)
        {
            swap(p_a, p_c);
        }

        // 3. 如果 b > c，交换 b 和 c 的值
        if (*p_b > *p_c)
        {
            swap(p_b, p_c);
        }

        // 顺序输出结果
        printf("由小到大的顺序是: %d %d %d\n", *p_a, *p_b, *p_c);
    }

    return 0;
}
