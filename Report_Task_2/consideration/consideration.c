#include <stdio.h>
#include <stdlib.h>

typedef struct BINARYTREE
{
    int value;
    struct binaryTree *left;
    struct binaryTree *right;
} binaryTree;

static binaryTree *root = NULL;

int compare(const void *a, const void *b);
void addNode(binaryTree **node, int value);
void printNode(binaryTree *now);

int main(void)
{
    int i;
    int array[] = {1, 1, 3, 5, 6, 4, 7, 5, 4, 3, 7, 9, 5, 4, 2, 6};
    size_t sizeInt = sizeof(int);
    size_t sizeArray = sizeof(array) / sizeof(int);
    addNode(&root, 5);
    for (i = 0; i < sizeArray; i++)
    {
        addNode(&root, array[i]);
    }
    printNode(root);
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void addNode(binaryTree **node, int value)
{
    int result;
    if ((*node) == NULL)
    {
        (*node) = malloc(sizeof(binaryTree));
        if ((*node) == NULL)
        {
            fprintf(stderr, "NULL");
            return;
        }
        (*node)->left = NULL;
        (*node)->right = NULL;
        (*node)->value = value;
        return;
    }

    if ((*node)->value < value)
    {
        result = 1;
    }
    else if ((*node)->value > value)
    {
        result = -1;
    }
    else if ((*node)->value == value)
    {
        result = 0;
    }

    if (0 < result)
    {
        addNode(&(*node)->right, value);
    }
    else
    {
        addNode(&(*node)->left, value);
    }
}

void printNode(binaryTree *now)
{
    if (now == NULL)
        return;

    printNode(now->left);
    printf("%d\n", now->value);
    printNode(now->right);
}
