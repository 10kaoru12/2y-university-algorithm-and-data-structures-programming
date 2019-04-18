#include <stdio.h>
int main(void)
{
    int graph[9][9] = {0};
    int count = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0 + count; j < 9 - count; j++)
        {
            graph[0 + count][j] = 1;
            graph[j][8 - count] = 1;
        }
        count += 2;
    }
    count = 0;
    int ycount = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0 + count; j < 9 - ycount; j++)
        {
            graph[j][0 + count] = 1;
        }
        ycount++;
        count += 2;
    }

    count = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 2 + count; j < 9 - count; j++)
        {
            graph[8 - count][j] = 1;
        }
        count += 2;
    }

    //output
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (graph[i][j] == 1)
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