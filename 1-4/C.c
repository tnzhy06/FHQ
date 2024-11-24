#include <stdio.h>

#define MAX_N 100

int n, k;
long fd[MAX_N + 1][MAX_N + 1];
int must[11] = {0};               // 必经点
long m;                           // 初始能量
long long min_cost = 10000000000; // 最小消耗

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (fd[i][j] > fd[i][k] + fd[k][j])
                    fd[i][j] = fd[i][k] + fd[k][j];
}

void dfs(int node, long current_cost, int visited[], int cnt)
{
    cnt++;
    if (current_cost >= min_cost)
        return;

    if (cnt == k)
    {
        current_cost += fd[node][n];
        min_cost = current_cost < min_cost ? current_cost : min_cost;
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (visited[must[i]])
        {
            visited[must[i]] = 0;
            dfs(must[i], current_cost + fd[node][must[i]], visited, cnt);
            visited[must[i]] = 1;
        }
    }
}

int main()
{
    scanf("%d %ld", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            long cost;
            scanf("%ld", &cost);
            fd[i][j] = cost;
        }
    }

    scanf("%d", &k);

    for (int i = 0; i < k; i++)
        scanf("%d", &must[i]);

    floyd();

    int visited[MAX_N + 1] = {0}; // 0表示访问过，1表示未访问
    int cnt = 0;

    for (int i = 0; i < k; i++)
    { // dfs时只所搜必经点
        visited[must[i]] = 1;
        if (must[i] == 1)
        {
            cnt++;
        }
    }
    visited[1] = 0;
    visited[n] = 0;

    dfs(1, 0, visited, cnt);

    if (min_cost <= m)
        printf("%lld\nYES\n", min_cost);
    else
        printf("%lld\nNO\n", min_cost);

    return 0;
}