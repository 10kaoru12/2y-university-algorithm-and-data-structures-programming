#include <stdio.h>
#define ZEI (1.08)

typedef struct
{
	char *name;
	int tanka;
	int sotozei;
} SHOHIN;

SHOHIN shohin[] = {{"Apple", 150}, {"Orange", 100}, {"Banana", 200}, {"Book1", 500, 1}, {"", 0}};

void printshohin(SHOHIN s)
{

	char *uti = "内税";
	char *soto = "外税";
	char *name = s.name;
	int sotozei = s.sotozei;
	int tanka = s.tanka;

	if (s.sotozei == 0)
	{
		printf("%s\t単価%d円(%s)", name, tanka, uti);
	}
	else
	{
		printf("%s\t単価%d円(外税)", name, tanka, soto);
	}
}
int main(void)
{
	int i;
	for (i = 0; shohin[i].tanka != 0; i++)
	{
		printf("商品コード %d 品名 ", i);
		printshohin(shohin[i]);
		printf("\n");
	}
	return 0;
}
