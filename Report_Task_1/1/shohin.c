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
  if (s.sotozei == 0)
  {
    printf("%s\t単価%d円(内税)", s.name, s.tanka);
  }
  else
  {
    printf("%s\t単価%d円(外税)", s.name, s.tanka);
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
