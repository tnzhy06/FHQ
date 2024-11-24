#include <stdio.h>
#include <string.h>

char str1[1600000];
char str2[390000];
int p[1600000];
int next[390000];

void build_next(char str2[], int len2)
{
    int s_len = 0;
    int i = 1;
    next[0] = 0;
    while (i < len2)
    {
        if (str2[s_len] == str2[i])
        {
            s_len++;
            next[i++] = s_len;
        }
        else
        {
            if (s_len == 0)
            {
                next[i++] = 0;
            }
            else
            {
                s_len = next[s_len - 1];
            }
        }
    }
}

int kmp(char str1[], char str2[], int p[])
{
    int n = 0;
    int i = 0;
    int j = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    build_next(str2, len2);

    while (i < len1)
    {
        if (str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else if (j > 0)
        {
            j = next[j - 1];
        }
        else
        {
            i++;
        }

        if (j == len2)
        {
            p[n++] = i - j;
            j = next[j - 1];
        }
    }
    return n;
}

int main()
{
    fgets(str1, sizeof(str1), stdin);
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    int n = kmp(str1, str2, p);

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", p[i] + 1);
    }

    return 0;
}