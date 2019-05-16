#include <stdio.h>
int i;
int a(int i)
{
    i++;
    return i;
}
int b(int j)
{
    i++;
    return i;
}
int c(int k)
{
    int i;
    i = 0;
    return i;
}
int main(void)
{
    i = 1;
    printf("%d\n", i);
    printf("%d ", a(i));
    printf("%d\n", i);
    printf("%d ", b(i));
    printf("%d\n", i);
    printf("%d ", c(i));
    printf("%d\n", i);
    return 0;
}