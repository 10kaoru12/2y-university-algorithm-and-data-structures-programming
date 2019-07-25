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
    clock_t start, end;
    double sum = 0;
    int i;
    for (i = 0; i < 10; i++)
    {
        start = clock();
        URIAGE u1 = {1, 2};
        URIAGE u2 = {2, 3};
        URIAGE u3 = {3, 4};
        URIAGE *u[] = {&u1, &u2, &u3, NULL};
        URIAGE **p;
        URIAGELIST *l;
        URIAGELIST *m;
        if ((l = newlist()) == NULL)
        {
            fprintf(stderr, "領域を確保できませんでした");
            return 2;
        }
        for (p = u; *p != NULL; p++)
        {
            if ((m = add(l, *p)) == NULL)
            {
                fprintf(stderr, "領域を確保できませんでした");
                freeUriageList(l, 0);
                return 2;
            }
            printf("追加%s\n", m->uriage == *p ? "OK" : "NG");
            printUriageList(l);
            printf("-----\n");
        }
        freeUriageList(l, 0);
        end = clock();
        sum += (double)(end - start) / CLOCKS_PER_SEC;
    }
    sum /= 10;
    printf("%.10f?\n", sum);
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
    while (l->next != NULL)
    {
        //lのURIAGE型のメンバーuriageのポインタである*uriageにアロー演算子でアクセスする。
        //*uriageのメンバであるcodeにアクセス
        sotozei = shohin[l->uriage->code].sotozei;
        tanka = shohin[l->uriage->code].tanka;
        //*uriageのメンバであるnumにアロー演算子でアクセス
        num = l->uriage->num;
        name = shohin[l->uriage->code].name;
        syoukei = num * tanka;
        zeisyoukei = num * tanka * ZEI;
        //最後のノードかそれ以外かの判断
        if (l != NULL)
        {
            //sotozeiがtrueかflaseかで外税か内税かを判別
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
        l = l->next;
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
        l->next = NULL;
        l->uriage = '\0';
    }
    //明示的にreturn NULL
    else
    {
        return NULL;
    }
    return l;
}

void freeUriageList(URIAGELIST *l, int purge)
{
    //free対象のURIAGELIST型のポインタ変数の宣言
    URIAGELIST *next;
    //purgeのtrueかfalseの判断
    if (purge)
    {
        while (l != NULL)
        {
            //次にfreeする構造体をnextにコピー
            next = l->next;
            free(l);
            l = next;
        }
    }
    else
    {
        while (l != NULL)
        {
            next = l->next;
            free(l->next);
            l = next;
        }
    }
}

URIAGELIST *add(URIAGELIST *l, URIAGE *u)
{
    if (l->next != NULL)
    {
        return add(l->next, u);
    }
    if ((l->next = newlist()) != NULL)
    {
        l->uriage = u;
    }
    return l;
}
