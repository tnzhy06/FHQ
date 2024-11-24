#include <stdio.h>

int main()
{
    int n, m, o, p;
    scanf("%d %d %d %d", &n, &m, &o, &p);

    if (m != o || m == 0 || o == 0)
        return 0;

    int A[n][m];
    int B[o][p];
    int C[n][p];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    for (int i = 0; i < o; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < m; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}