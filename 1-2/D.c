#include <stdio.h>
#include <string.h>

int n;
int rings[20];

void down(int n);
void up(int n);

void czdy(int c)
{
    if (rings[c])
    {
        rings[c] = 0;
    }
    else
    {
        rings[c] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", rings[i]);
    }
    printf("\n");
}

void down(int n)
{
    if (n == 1)
    {
        czdy(0);
    }
    else if (n == 2)
    {
        czdy(1);
        down(1);
    }
    else
    {
        down(n - 2);
        czdy(n - 1);
        up(n - 2);
        down(n - 1);
    }
}

void up(int n)
{
    if (n == 1)
    {
        czdy(0);
    }
    else if (n == 2)
    {
        up(1);
        czdy(1);
    }
    else
    {
        up(n - 1);
        down(n - 2);
        czdy(n - 1);
        up(n - 2);
    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        rings[i] = 1;
    }

    down(n);

    return 0;
}