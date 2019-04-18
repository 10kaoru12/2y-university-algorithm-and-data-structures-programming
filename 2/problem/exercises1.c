#include <stdio.h>
int main(void)
{
    int graph[9][9];
    
    //??
    for (int i = 0; i < 9; i++)
    {
        graph[0][i] = 1;
        graph[8][i] = 1;
    }
    for (int i = 0; i < 9; i++)
    {
        graph[i][0] = 1;
        graph[i][8] = 1;
    }

    //??
    for (int i = 2; i < 7; i++)
    {
        graph[2][i] = 1;
        graph[6][i] = 1;
    }
    for (int i = 2; i < 7; i++)
    {
        graph[i][2] = 1;
        graph[i][6] = 1;
    }

    //??
    graph[4][4] = 1;

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
}