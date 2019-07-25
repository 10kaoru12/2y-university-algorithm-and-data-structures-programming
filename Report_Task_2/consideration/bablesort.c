#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    time_t start, end;
    start = clock();
    int i;
    int array[] = {1, 1, 3, 5, 6, 4, 7, 5, 4, 3, 7, 9, 5, 4, 2, 6};
    size_t sizeInt = sizeof(int);
    size_t sizeArray = sizeof(array) / sizeof(int);
    qsort(array, sizeArray, sizeInt, compare_int);
    for (i = 0; i < sizeArray; i++)
    {
        printf("%d\n", array[i]);
    }
    end = clock();
    printf("%.10f秒\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
