#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n = 0, max_s;
    scanf("%d", &max_s);
    max_s = (int)(max_s * 0.3);
    int s[128], v[128]; // s: 云的体积，v: 云的价值
    int dp[20039] = {0};

    while (scanf("%d %d", &s[n], &v[n]) != EOF)
    {
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = max_s; j >= s[i]; j--) // 从后向前覆盖
        {
            dp[j] = max(dp[j], dp[j - s[i]] + v[i]);
        }
    }

    printf("%d", dp[max_s]);
    return 0;
}