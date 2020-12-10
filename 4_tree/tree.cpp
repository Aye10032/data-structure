#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef int ElemType;

typedef struct BiNode
{
    ElemType data;
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

void init(BiTree *tree)
{
    *tree = (BiNode *)malloc(sizeof(BiNode));
    (*tree)->data = 1;

    (*tree)->lchild = (BiNode *)malloc(sizeof(BiNode));
    (*tree)->lchild->data = 2;
    (*tree)->rchild = (BiNode *)malloc(sizeof(BiNode));
    (*tree)->rchild->data = 3;

    (*tree)->lchild->lchild = (BiNode *)malloc(sizeof(BiNode));
    (*tree)->lchild->lchild->data = 4;
    (*tree)->lchild->rchild = (BiNode *)malloc(sizeof(BiNode));
    (*tree)->lchild->rchild->data = 5;
    (*tree)->rchild->lchild = NULL;
    (*tree)->rchild->rchild = NULL;

    (*tree)->lchild->lchild->lchild = NULL;
    (*tree)->lchild->lchild->rchild = NULL;
    (*tree)->lchild->rchild->lchild = NULL;
    (*tree)->lchild->rchild->rchild = NULL;
}

int main()
{
    BiTree Tree;
    init(&Tree);

    
}
