#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[] = "Madam,I'm Adam.";
    int size = strlen(str);
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if ('!' <= str[i] && str[i] <= '@')
        {
            str[i] = ' ';
        }
    }
    for (int i = 0; i < size; i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (str[i] == ' ')
        {
            cnt++;
            ans[i] = str[i + cnt];
        }
        else
        {
            ans[i] = str[i + cnt];
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%c", ans[i]);
    }
    for (int i = 0; i < size / 2; i++)
    {
        if (str[i] != str[size - i])
        {
            printf("回文で無い\n");
            return 0;
        }
    }
    printf("回文である\n");
    return 0;
}