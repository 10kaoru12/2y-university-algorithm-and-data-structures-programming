#include <stdio.h>
#define ZEI 1.08

typedef struct{
  char* name;
  int tanka;
  int sotozei;
} SHOHIN;

typedef struct {
  int code;
  int num;
} URIAGE;

SHOHIN shohin[]={{"Apple",150},{"Orange",100},{"Banana",200},{"Book1",500,1},{"",0}};

int printUriageArray(URIAGE u[]){
    double sum;
    int i;
    for (i = 0; u[i].code != (-1); i++)
    {
        if(shohin[u[i].code].sotozei==0){
            printf("%s\t単価%d円(内税) %d 個\t%d 円\n",shohin[u[i].code].name,shohin[u[i].code].tanka,u[i].num,shohin[u[i].code].tanka*u[i].num);
            sum+=shohin[u[i].code].tanka*u[i].num;
        }
        else
        {
          printf("%s\t単価%d円(外税) %d 個\t%f 円\n", shohin[u[i].code].name, shohin[u[i].code].tanka, u[i].num, shohin[u[i].code].tanka * u[i].num * ZEI);
          sum += shohin[u[i].code].tanka * u[i].num * ZEI;
        }
    }
    printf("小計:\t\t\t\t%f円\n", sum);
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
