#include <stdio.h>
int main(void)
{
    int a[] = {5, 2, 6, 3, 1, -1};
    for (int i = 0; a[i] != -1; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            printf("O");
        }
        printf("\n");
    }
    return 0;
}