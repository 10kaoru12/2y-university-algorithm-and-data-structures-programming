#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct uriagelist
{
    struct uriagelist *next;
    URIAGE *uriage;
} URIAGELIST;

void printUriageList(URIAGELIST *l);
URIAGELIST *newlist(void);
void freeUriageList(URIAGELIST *l, int purge);
URIAGELIST *add(URIAGELIST *l, URIAGE *u);

SHOHIN shohin[] = {{"Apple", 150}, {"Orange", 100}, {"Banana", 200}, {"Book1", 500, 1}, {"", 0}};

int main(void)
{
    URIAGE u1 = {1, 2};
    URIAGE u2 = {2, 3};
    URIAGE u3 = {3, 4};
    URIAGELIST *l0;
    URIAGELIST *l1;
    URIAGELIST *l2;
    URIAGELIST *l3;
    if ((l0 = newlist()) == NULL)
    {
        fprintf(stderr, "領域を確保できませんでした");
        return 2;
    }
    if ((l1 = newlist()) == NULL)
    {
        fprintf(stderr, "領域を確保できませんでした");
        free(l0);
        return 2;
    }
    if ((l2 = newlist()) == NULL)
    {
        fprintf(stderr, "領域を確保できませんでした");
        free(l1);
        free(l0);
        return 2;
    }
    if ((l3 = newlist()) == NULL)
    {
        fprintf(stderr, "領域を確保できませんでした");
        free(l2);
        free(l1);
        free(l0);
        return 2;
    }
    printUriageList(l0);
    printf("-----\n");
    (*l1).next = l0;
    (*l1).uriage = &u1;
    printUriageList(l1);
    printf("-----\n");
    (*l2).next = l1;
    (*l2).uriage = &u2;
    printUriageList(l2);
    printf("-----\n");
    (*l3).next = l2;
    (*l3).uriage = &u3;
    printUriageList(l3);
    printf("-----\n");
    free(l3);
    free(l2);
    free(l1);
    free(l0);
    return 0;
}

void printUriageList(URIAGELIST *l)
{
    int sotozei;
    int tanka;
    int num;
    char *name;
    int syoukei;
    double zeisyoukei;
    while ((*l).next != NULL)
    {
        //lのURIAGE型のメンバーuriageのポインタである*uriageにアロー演算子でアクセスする。
        //*uriageのメンバであるcodeにアクセス
        sotozei = shohin[(*(*l).uriage).code].sotozei;
        tanka = shohin[(*(*l).uriage).code].tanka;
        //*uriageのメンバであるnumにアロー演算子でアクセス
        num = (*(*l).uriage).num;
        name = shohin[(*(*l).uriage).code].name;
        syoukei = num * tanka;
        zeisyoukei = num * tanka * ZEI;
        //最後のノードかそれ以外かの判断
        if (l != NULL)
        {
            //sotozeiがtrueかfalseかで外税か内税かを判別
            if (sotozei)
            {
                printf("%s\t単価%d円(外税) %d 個\t%.0f 円\n", name, tanka, num, zeisyoukei);
            }
            else
            {
                printf("%s\t単価%d円(内税) %d 個\t%d 円\n", name, tanka, num, syoukei);
            }
        }
        //次にprintする対象である構造体をl->nextを使って参照して代入
        l = (*l).next;
    }
}

URIAGELIST *newlist(void)
{
    URIAGELIST *l;
    //メモリの取得を試みる
    l = malloc(sizeof(URIAGELIST));
    //mallocでのメモリ取得の成否判断
    if (l != NULL)
    {
        (*l).next = NULL;
        (*l).uriage = '\0';
    }
    //明示的return NULLを示す
    else
    {
        return NULL;
    }
    return l;
}
