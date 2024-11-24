#include <stdio.h>

int main()
{
    long n, sum = 0;
    scanf("%ld", &n);
    long arr[n], qianzhuihe[n + 1];
    qianzhuihe[0] = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
        qianzhuihe[i + 1] = arr[i] + qianzhuihe[i];
    }

    for (int i = 1; i < n; i++)
    {
        sum += arr[i] * qianzhuihe[i];
    }

    printf("%ld", sum);

    return 0;
}