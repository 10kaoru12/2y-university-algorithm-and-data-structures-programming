#include <stdio.h>
int main(void)
{
    int a[] = {5, 2, 6, 3, 1, -1};
    for (int i = 0; a[i] != -1; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}