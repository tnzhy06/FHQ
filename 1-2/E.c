#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 115309

int min(int a, int b)
{
    return a < b ? a : b;
}

int w(int h[], int n)
{
    int stack[MAX];
    int top = -1;
    int water = 0;

    for (int i = 0; i < n; i++)
    {
        while (top != -1 && h[stack[top]] < h[i])
        {
            int pop = stack[top--];
            if (top == -1)
            {
                break;
            }
            int height = min(h[i], h[stack[top]]) - h[pop];
            int length = i - stack[top] - 1;
            water += height * length;
        }
        top++;
        stack[top] = i;
    }

    return water;
}

int main()
{
    char input[MAX];
    int h[MAX];
    int n;
    while (scanf("%s", input) != EOF)
    {
        n = 0;
        char *a = strtok(input, "P");
        while (a != NULL)
        {
            h[n++] = atoi(a);
            a = strtok(NULL, "P");
        }
        int water = w(h, n);
        printf("%d\n", water);
    }

    return 0;
}