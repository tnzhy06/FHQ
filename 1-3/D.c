#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[10000] = {1};
    int m = 1;

    for (int i = 0; i < n; i++)
    {
        int k = 0;
        int temp;
        for (int j = 0; j < m; j++)
        {
            temp = arr[j] * 2 + k;
            k = temp / 10;
            arr[j] = temp % 10;
        }
        while (k)
        {
            arr[m++] = k % 10;
            k /= 10;
        }
    }

    arr[0] -= 1;

    printf("%d\n", m);

    for (int i = 99; i >= 0; i--)
    {
        if (arr[i] > 0)
        {
            printf("%d", arr[i]);
        }
        else
        {
            printf("0");
        }
    }

    return 0;
}