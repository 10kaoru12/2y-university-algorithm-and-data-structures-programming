#include <chrono>
#include <iostream>

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
    auto start = std::chrono::system_clock::now();
    int a;
    int b;
    int l;

    int r;
    int s, g;

    for (i = 0; i < size; ++i)
    {
        cost[i] = inf;
        flag[i] = 0;
        for (j = 0; j < size; ++j)
        {
            dist[i][j] = inf;
        }
    }

    scanf("%d%d", &n, &r);
    for (i = 0; i < r; ++i)
    {
        scanf("%d%d%d", &a, &b, &l);
        dist[a][b] = l;
    }
    scanf("%d%d", &s, &g);
    {
        printf("distance:%d\n", dijkstra(s, g));
    }
    auto end = std::chrono::system_clock::now(); // 計測終了時刻を保存
    auto dur = end - start;                      // 要した時間を計算
    auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    // 要した時間をミリ秒（1/1000秒）に変換して表示
    std::cout << msec << " milli sec \n";
    return 0;
}
