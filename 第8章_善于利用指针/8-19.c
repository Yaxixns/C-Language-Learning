/*
 * 习题19
 * （1）编写一个函数 new，对 n 个字符开辟连续的存储空间，
 *      此函数应返回一个指针（地址），指向字符串开始的空间。
 *      new(n) 表示分配 n 个字节的内存空间。
 * （2）写一函数 free，将前面用 new 函数占用的空间释放。
 *      free(p) 表示将 p（地址）指向的单元以后的内存段释放。
 *
 * 实现思路：
 *   用一个大数组 mem 作为"内存池"，used 数组标记每个字节是否已分配，
 *   blk_size 数组记录每个分配块的大小（仅在块首字节有意义）。
 *   new(n)：扫描 mem，找到连续 n 个空闲字节，标记为已用，返回首指针。
 *   free(p)：从 p 位置读出块大小，将该块所有字节标记为空闲。
 */

#include <stdio.h>

#define MAX_MEM 10000 /* 内存池总大小 */

char mem[MAX_MEM];           /* 模拟堆内存 */
char used[MAX_MEM] = {0};    /* 标记字节是否已分配: 1-已用, 0-空闲 */
int blk_size[MAX_MEM] = {0}; /* 块大小（仅在块首字节有意义） */

/* ---------- new: 分配 n 个字节，返回首地址 ---------- */
char *new(int n)
{
    int i, j;

    if (n <= 0 || n > MAX_MEM)
        return NULL;

    /* 在内存池中找连续 n 个空闲字节 */
    for (i = 0; i <= MAX_MEM - n; i++)
    {
        int found = 1;
        for (j = 0; j < n; j++)
        {
            if (used[i + j])
            {
                found = 0;
                break;
            }
        }
        if (found)
        {
            /* 标记这 n 个字节为已用 */
            for (j = 0; j < n; j++)
                used[i + j] = 1;
            blk_size[i] = n; /* 在块首记录大小 */
            return mem + i;  /* 返回指向该块的指针 */
        }
    }
    return NULL; /* 没有足够连续空间 */
}

/* ---------- free: 释放 p 指向的内存块 ---------- */
void free_mem(char *p)
{
    int i, n;

    if (p == NULL)
        return;
    if (p < mem || p >= mem + MAX_MEM)
        return; /* 无效指针 */

    i = (int)(p - mem); /* 计算 p 在 mem 中的下标 */
    n = blk_size[i];    /* 读出该块的大小 */

    if (n <= 0)
        return; /* 不是有效块 */

    /* 将该块的字节全部标记为空闲 */
    for (int j = 0; j < n; j++)
        used[i + j] = 0;
    blk_size[i] = 0;
}

/* ---------- 测试 main ---------- */
int main()
{
    char *s1, *s2, *s3;
    int i;

    /* 测试 1: 分配两个字符串 */
    s1 = new(20);
    s2 = new(10);

    if (s1 && s2)
        printf("s1 = %p, s2 = %p  分配成功！\n", (void *)s1, (void *)s2);
    else
        printf("分配失败！\n");

    /* 向 s1 写入字符串 */
    if (s1)
    {
        char str[] = "Hello, World!";
        for (i = 0; str[i] != '\0'; i++)
            s1[i] = str[i];
        s1[i] = '\0';
        printf("s1 内容: %s\n", s1);
    }

    /* 测试 2: 释放 s1 后再分配 */
    free_mem(s1);
    printf("已释放 s1\n");

    s3 = new(15);
    if (s3)
        printf("s3 = %p (应该在 s1 原来的位置)\n", (void *)s3);

    /* 清理 */
    free_mem(s2);
    free_mem(s3);

    getchar();
    return 0;
}
