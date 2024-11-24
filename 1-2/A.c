#include <stdio.h>
#include <string.h>

void jiami(int n, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z')
            ch = (ch - 'A' + n + 26) % 26 + 'A';
        else if (ch >= 'a' && ch <= 'z')
            ch = (ch - 'a' + n + 26) % 26 + 'a';
        else if (ch >= '0' && ch <= '9')
            ch = (ch - '0' + n + 10) % 10 + '0';
        str[i] = ch;
    }
}

int main()
{
    int n;
    char str[1001];

    scanf("%d", &n);
    getchar();
    fgets(str, sizeof(str), stdin);
    jiami(n, str);
    printf("%s", str);

    return 0;
}