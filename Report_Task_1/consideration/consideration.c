#include <stdio.h>

#define inf 9999999
#define size 10000

int n, i, j, neigh;
int dist[size][size];
int cost[size];
int flag[size];
int use[size];

int dijkstra(const int start, const int goal)
{
    int min, target;
    cost[start] = 0;
    while (1)
    {
        min = inf;
        for (i = 0; i < n; ++i)
        {
            if (!use[i] && min > cost[i])
            {
                min = cost[i];
                target = i;
            }
        }

        if (target == goal)
        {
            return cost[goal];
        }

        for (neigh = 0; neigh < n; ++neigh)
        {
            if (cost[neigh] > dist[target][neigh] + cost[target])
            {
                cost[neigh] = dist[target][neigh] + cost[target];
            }
        }
        use[target] = 1;
    }
}

int main(void)
{
    typedef struct
    {
        int a;
        int b;
        int l;
    } GP;

    int r;
    const int s, g;

    for (i = 0; i < size; ++i)
    {
        cost[i] = inf;
        flag[i] = 0;
        for (j = 0; j < size; ++j)
        {
            dist[i][j] = inf;
        }
    }

    GP gp;
    scanf("%d%d", &n, &r);
    for (i = 0; i < r; ++i)
    {
        scanf("%d%d%d", &gp.a, &gp.b, &gp.l);
        dist[gp.a][gp.b] = gp.l;
    }
    scanf("%d%d", &s, &g);

    printf("distance:%d\n", dijkstra(s, g));

    return 0;
}
