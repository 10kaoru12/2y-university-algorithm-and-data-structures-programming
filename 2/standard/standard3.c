#include <stdio.h>
int main(void)
{
    int a[] = {5, 2, 6, 3, 1, -1};
    int sum = 0, i;
    for (i = 0; a[i] != -1; i++)
    {
        sum += a[i];
    }
    printf("%d", sum / i);
    return 0;
}