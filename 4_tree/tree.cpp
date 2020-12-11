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
    (*tree)->rchild->lchild = (BiNode *)malloc(sizeof(BiNode));
    (*tree)->rchild->lchild->data = 6;
    (*tree)->rchild->rchild = NULL;

    (*tree)->lchild->lchild->lchild = NULL;
    (*tree)->lchild->lchild->rchild = NULL;
    (*tree)->lchild->rchild->lchild = NULL;
    (*tree)->lchild->rchild->rchild = NULL;
    (*tree)->rchild->lchild->lchild = NULL;
    (*tree)->rchild->lchild->rchild = NULL;
}

//先序遍历
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        cout << T->data << endl;
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

//中序遍历
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        InOrder(T->lchild);
        cout << T->data << endl;
        InOrder(T->rchild);
    }
}

//后序遍历
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T->data << endl;
    }
}

int main()
{
    BiTree Tree;
    init(&Tree);

    cout << "PreOrder:" << endl;
    PreOrder(Tree);
    cout << "InOrder:" << endl;
    InOrder(Tree);
    cout << "PostOrder:" << endl;
    PostOrder(Tree);
    system("pause");
}
