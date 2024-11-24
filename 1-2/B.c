#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(char *)b - *(char *)a);
}

int main()
{
    char str[1001];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    qsort(str, len, sizeof(char), compare);
    printf("%s", str);
    return 0;
}