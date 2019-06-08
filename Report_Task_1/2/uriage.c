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
  if (shohin[q->code].sotozei == 0)
  {
    printf("%s\t単価%d円(内税) %d 個\t%d 円\n", shohin[q->code].name, shohin[q->code].tanka, q->num, shohin[q->code].tanka * q->num);
    return shohin[q->code].tanka * q->num;
  }
  else
  {
    printf("%s\t単価%d円(外税) %d 個\t%.0f 円\n", shohin[q->code].name, shohin[q->code].tanka, q->num, shohin[q->code].tanka * q->num * ZEI);
    return shohin[q->code].tanka * q->num * ZEI;
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
