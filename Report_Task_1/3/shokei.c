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

int printUriageArray(URIAGE u[])
{
	int i;
	int sotozei;
	int tanka;
	int num;
	int syoukei;
	char *name;
	double zeisyoukei;
	double sum;
	for (i = 0; u[i].code != (-1); i++)
	{

		name = shohin[u[i].code].name;
		sotozei = shohin[u[i].code].sotozei;
		tanka = shohin[u[i].code].tanka;
		num = u[i].num;
		syoukei = shohin[u[i].code].tanka * u[i].num;
		zeisyoukei = shohin[u[i].code].tanka * u[i].num * ZEI;

		if (sotozei == 0)
		{
			printf("%s\t単価%d円(内税) %d 個\t%d 円\n", name, tanka, num, syoukei);
			sum += syoukei;
		}
		else
		{

			printf("%s\t単価%d円(外税) %d 個\t%.0f 円\n", name, tanka, num, zeisyoukei);
			sum += zeisyoukei;
		}
	}
	printf("小計:\t\t\t\t%.0f円\n", sum);
	return sum;
}
int main(void)
{
	URIAGE u[] = {{0, 3}, {1, 2}, {2, 1}, {3, 4}, {-1}};
	int shokei;
	shokei = printUriageArray(u);
	printf("\t%d\n", shokei);
	return 0;
}
