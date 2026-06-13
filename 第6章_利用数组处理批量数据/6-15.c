/*
 * 习题15
 * 编写一个程序，将字符数组 s2 中的全部字符复制到字符数组 s1 中。
 * 不用 strcpy 函数。复制时，'\0' 也要复制过去。'\0' 后面的字符不复制。
 */

#include <stdio.h>

int main()
{
    char s1[100];
    char s2[100] = "hoiuhawfoihiwa";
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = s2[i];
    printf("%s\n", s1);
    getchar();
    return 0;
}
