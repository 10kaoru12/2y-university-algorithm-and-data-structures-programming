#include <stdio.h>
int main(void)
{
    printf("10進数:8進数:16進数:文字コード\n");
    for (int i = 33; i <= 126; i++)
    {
        printf("%4d:%4o:%4x:%4c\n", i, i, i, i);
    }
    return 0;
}