#include <stdio.h>
#define ZEI 1.08

typedef struct
{
    char *name;
    int tanka;
    int sotozei;
} SHOHIN;

typedef struct
{
    int code;
    int num;
} URIAGE;

SHOHIN shohin[] = {{"Apple", 150}, {"Orange", 100}, {"Banana", 200}, {"Book1", 500, 1}, {"", 0}};

int printUriageTrans(URIAGE **u)
{
    double sum;
    int i, j;
    for (i = 0; u[i] != NULL; i++)
    {
        for (int j = 0; u[i][j].code != (-1); j++)
        {
            if (shohin[u[i][j].code].sotozei == 0)
            {
                printf("%s\t単価%d円(内税) %d 個\t%d 円\n", shohin[u[i][j].code].name, shohin[u[i][j].code].tanka, u[i][j].num, shohin[u[i][j].code].tanka * u[i][j].num);
                sum += shohin[u[i][j].code].tanka * u[i][j].num;
            }
            else
            {
                printf("%s\t単価%d円(外税) %d 個\t%.0f 円\n", shohin[u[i][j].code].name, shohin[u[i][j].code].tanka, u[i][j].num, shohin[u[i][j].code].tanka * u[i][j].num * ZEI);
                sum += shohin[u[i][j].code].tanka * u[i][j].num * ZEI;
            }
        }
        printf("小計:\t\t\t\t%.0f円\n", sum);
        printf("------------------\n");
    }
    printf("合計:\t\t\t\t%.0f円\n", sum);
    return sum;
}

int main(void)
{
    URIAGE uriage0[] = {{2, 1}, {1, 6}, {-1}};
    URIAGE uriage1[] = {{0, 3}, {1, 2}, {2, 1}, {-1}};
    URIAGE uriage2[] = {{3, 1}, {-1}};
    URIAGE uriage3[] = {{1, 3}, {0, 1}, {-1}};
    URIAGE uriage4[] = {{1, 3}, {0, 1}, {3, 2}, {-1}};
    URIAGE *uriage[] = {uriage0, uriage1, uriage2, uriage3, uriage4, NULL};
    int total;
    total = printUriageTrans(uriage);
    printf("%d\n", total);
    return 0;
}
