#include <stdio.h>
int main(void)
{
    char x[] = "This is a pin.";
    int cnt = 0;
    for (int i = 0; x[i] != '\0'; i++)
    {
        if (x[i] == 'i')
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}