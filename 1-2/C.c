int my_strlen(const char *str);
char *my_strcpy(char *, const char *);
int my_strcmp(const char *, const char *);
char *my_strcat(char *, const char *);

int my_strlen(const char *str)
{
    int cnt = 0;
    while (*str != '\0')
    {
        cnt++;
        str++;
    }
    return cnt;
}

char *my_strcpy(char *dest, const char *src)
{
    char *result = dest;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return result;
}

int my_strcmp(const char *a, const char *b)
{
    while (*a != '\0' || *b != '\0')
    {
        if (*a == *b)
        {
            a++;
            b++;
        }
        else
        {
            return (*a > *b) ? 1 : -1;
        }
    }
    return 0;
}

char *my_strcat(char *dest, const char *src)
{
    char *t = dest;
    while (*t != '\0')
    {
        t++;
    }
    while (*src != '\0')
    {
        *t = *src;
        t++;
        src++;
    }
    *t = '\0';
    return dest;
}