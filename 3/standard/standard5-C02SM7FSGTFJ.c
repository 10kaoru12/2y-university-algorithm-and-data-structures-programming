#include <stdio.h>
int main(void)
{
    char x[] = "abc";
    char y[] = "def";
    char z[50];
    int cnt = 0;
    for (int i = 0; x[i] != '\0'; i++)
    {
        z[i] = x[i];
    }
    for (int i = 3; y[i - 3] != '\0'; i++)
    {
        z[i] = y[i - 3];
    }
    for (int i = 0; z[i] != '\0'; i++)
    {
        printf("%c", z[i]);
    }
    return 0;
}