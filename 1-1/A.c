#include <stdio.h>

int main()
{
    int h[1002];
    int i = 0;

    while (scanf("%d", &h[i]) != EOF)
    {
        if (i == 0 || h[i] > h[i - 1])
        {
            i++;
        }
    }

    printf("%d", i);
    return 0;
}