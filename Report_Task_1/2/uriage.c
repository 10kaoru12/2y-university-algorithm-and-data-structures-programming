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

int printUriage(URIAGE *q)
{
	int sotozei = shohin[q->code].sotozei;
	int tanka = shohin[q->code].tanka;
	int num = q->num;
	int syoukei = shohin[q->code].tanka * q->num;
	char *name = shohin[q->code].name;
	double zeisyoukei = shohin[q->code].tanka * q->num * ZEI;

	if (sotozei == 0)
	{

		printf("%s\t単価%d円(内税) %d 個\t%d 円\n", name, tanka, num, syoukei);
		return syoukei;
	}
	else
	{
		printf("%s\t単価%d円(外税) %d 個\t%.0f 円\n", name, tanka, num, zeisyoukei);
		return zeisyoukei;
	}
}
int main(void)
{
	URIAGE u1 = {0, 3};
	URIAGE u2 = {3, 4};
	int shokei;
	shokei = printUriage(&u1);
	printf("\t%d\n", shokei);
	shokei = printUriage(&u2);
	printf("\t%d\n", shokei);
	return 0;
}
