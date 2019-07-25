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
        URIAGE *u[] = {&u1, &u2, &u3, NULL};
        URIAGE **p;
        URIAGELIST *l;
        URIAGELIST *m;
        if ((l = newlist()) == NULL)
        {
            fprintf(stderr, "é ĺăç˘şäżă§ăăžăăă§ăă");
            return 2;
        }
        for (p = u; *p != NULL; p++)
        {
            if ((m = add(l, *p)) == NULL)
            {
                fprintf(stderr, "é ĺăç˘şäżă§ăăžăăă§ăă");
                freeUriageList(l, 0);
                return 2;
            }
            printf("čż˝ĺ %s\n", (*m).uriage == *p ? "OK" : "NG");
            printUriageList(l);
            printf("-----\n");
        }
        freeUriageList(l, 0);
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
        //lăŽURIAGEĺăŽăĄăłăăźuriageăŽăă¤ăłăżă§ăă*uriageăŤă˘ă­ăźćźçŽĺ­ă§ă˘ăŻăťăšăăă
        //*uriageăŽăĄăłăă§ăăcodeăŤă˘ăŻăťăš
        sotozei = shohin[(*(*l).uriage).code].sotozei;
        tanka = shohin[(*(*l).uriage).code].tanka;
        //*uriageăŽăĄăłăă§ăănumăŤă˘ă­ăźćźçŽĺ­ă§ă˘ăŻăťăš
        num = (*(*l).uriage).num;
        name = shohin[(*(*l).uriage).code].name;
        syoukei = num * tanka;
        zeisyoukei = num * tanka * ZEI;
        //ćĺžăŽăăźăăăăäťĽĺ¤ăăŽĺ¤ć­
        if (l != NULL)
        {
            //sotozeiătrueăflaseăă§ĺ¤ç¨ăĺç¨ăăĺ¤ĺĽ
            if (sotozei)
            {
                printf("%s\tĺäžĄ%dĺ(ĺ¤ç¨) %d ĺ\t%.0f ĺ\n", name, tanka, num, zeisyoukei);
            }
            else
            {
                printf("%s\tĺäžĄ%dĺ(ĺç¨) %d ĺ\t%d ĺ\n", name, tanka, num, syoukei);
            }
        }
        //ćŹĄăŤprintăăĺŻžčąĄă§ăăć§é ä˝ăl->nextăä˝żăŁăŚĺç§ăăŚäťŁĺĽ
        l = (*l).next;
    }
}

URIAGELIST *newlist(void)
{
    URIAGELIST *l;
    //ăĄă˘ăŞăŽĺĺžăčŠŚăżă
    l = malloc(sizeof(URIAGELIST));
    //mallocă§ăŽăĄă˘ăŞĺĺžăŽćĺŚĺ¤ć­
    if (l != NULL)
    {
        (*l).next = NULL;
        (*l).uriage = '\0';
    }
    //ćç¤şçăŤreturn NULL
    else
    {
        return NULL;
    }
    return l;
}

void freeUriageList(URIAGELIST *l, int purge)
{
    //freeĺŻžčąĄăŽURIAGELISTĺăŽăă¤ăłăżĺ¤ć°ăŽĺŽŁč¨
    URIAGELIST *next;
    //purgeăŽtrueăfalseăŽĺ¤ć­
    if (purge)
    {
        while (l != NULL)
        {
            //ćŹĄăŤfreeăăć§é ä˝ănextăŤăłăăź
s            next = (*l).next;
            free(l);
            l = next;
        }
    }
    else
    {
        while (l != NULL)
        {
            next = (*l).next;
            free((*l).next);
            l = next;
        }
    }
}

URIAGELIST *add(URIAGELIST *l, URIAGE *u)
{
    if ((*l).next != NULL)
    {
        return add((*l).next, u);
    }
    if (((*l).next = newlist()) != NULL)
    {
        (*l).uriage = u;
    }
    return l;
}
