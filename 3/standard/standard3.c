#include <stdio.h>
int main(void)
{
    char x[] = "This is a pin.";
    int cnt = 0;
    for (int i = 0; x[i] != '\0'; i++)
    {
        if ('a' <= x[i] && x[i] <= 'z')
        {
            printf("%c", x[i] - 'a' + 'A');
        }
        else
        {
            printf("%c", x[i]);
        }
    }
    return 0;
}