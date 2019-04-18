#include <stdio.h>
int graph[9][9];
int main(void)
{
    //out
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

    //in
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

    //center
    graph[4][4] = 1;

    //dropout
    graph[8][1] = 0;
    graph[6][3] = 0;
    graph[5][4] = 1;
    graph[7][2] = 1;

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