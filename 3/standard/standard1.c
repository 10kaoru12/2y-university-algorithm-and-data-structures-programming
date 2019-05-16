#include <stdio.h>
int main(void)
{
    char x[] = "abc";
    int cnt = 0;
    for (int i = 0; x[i] != '\0'; i++)
    {
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}