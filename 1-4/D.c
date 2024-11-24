#include <stdio.h>
#include <string.h>

long long a[15], len;
long long n, m, dp[15][1002][2];

long long dfs(int pos, long long sta, int limit)
{
    if (pos == 0)
        return sta == 0;
    if (dp[pos][sta][limit] != -1)
        return dp[pos][sta][limit];

    int up = limit ? a[pos] : 9;
    long long res = 0;
    for (int i = 0; i <= up; i++)
    {
        if (i == 7)
            continue;
        res += dfs(pos - 1, (sta * 10 + i) % m, limit && (i == up));
    }
    return dp[pos][sta][limit] = res;
}

int main()
{
    scanf("%lld %lld", &n, &m);

    while (n)
    {
        a[++len] = n % 10;
        n /= 10;
    }

    memset(dp, -1, sizeof(dp));
    long long ans = dfs(len, 0, 1) - 1;
    printf("%lld", ans);

    return 0;
}