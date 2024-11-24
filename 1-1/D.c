#include <stdio.h>

int main()
{
    int a[100000] = {1};
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                a[i] = a[i] + a[i - j];
                a[i] = a[i] % 100003;
            }
        }
    }

    printf("%d", a[n]);

    return 0;
}