#include <stdio.h>

#define x 9
#define y 9
#define zero 0
#define one 1
#define two 2
#define eight 8

int main(void)
{
    int graph[x][y] = {zero};
    int count = zero;
    for (int i = zero; i < two; i++)
    {
        for (int j = zero + count; j < x - count; j++)
        {
            graph[zero + count][j] = one;
            graph[j][eight - count] = one;
        }
        count += two;
    }
    count = zero;
    int ycount = zero;
    for (int i = zero; i < 3; i++)
    {
        for (int j = zero + count; j < x - ycount; j++)
        {
            graph[j][zero + count] = one;
        }
        ++ycount;
        count += two;
    }

    count = zero;
    for (int i = zero; i < two; i++)
    {
        for (int j = two + count; j < x - count; j++)
        {
            graph[eight - count][j] = one;
        }
        count += two;
    }

    //output
    for (int i = zero; i < y; i++)
    {
        for (int j = zero; j < x; j++)
        {
            if (graph[i][j] == one)
            {
                printf("O");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}