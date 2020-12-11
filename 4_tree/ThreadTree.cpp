#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef int ElemType;

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void init(ThreadTree *tree)
{
    *tree = (ThreadNode *)malloc(sizeof(ThreadNode));
    (*tree)->data = 1;
    (*tree)->ltag = 0;
    (*tree)->rtag = 0;

    (*tree)->lchild = (ThreadNode *)malloc(sizeof(ThreadNode));
    (*tree)->lchild->data = 2;
    (*tree)->lchild->ltag = 0;
    (*tree)->lchild->rtag = 0;
    (*tree)->rchild = (ThreadNode *)malloc(sizeof(ThreadNode));
    (*tree)->rchild->data = 3;
    (*tree)->rchild->ltag = 0;
    (*tree)->rchild->rtag = 0;

    (*tree)->lchild->lchild = (ThreadNode *)malloc(sizeof(ThreadNode));
    (*tree)->lchild->lchild->data = 4;
    (*tree)->lchild->lchild->ltag = 0;
    (*tree)->lchild->lchild->rtag = 0;
    (*tree)->lchild->rchild = (ThreadNode *)malloc(sizeof(ThreadNode));
    (*tree)->lchild->rchild->data = 5;
    (*tree)->lchild->rchild->ltag = 0;
    (*tree)->lchild->rchild->rtag = 0;
    (*tree)->rchild->lchild = (ThreadNode *)malloc(sizeof(ThreadNode));
    (*tree)->rchild->lchild->data = 6;
    (*tree)->rchild->lchild->ltag = 0;
    (*tree)->rchild->lchild->rtag = 0;
    (*tree)->rchild->rchild = NULL;

    (*tree)->lchild->lchild->lchild = NULL;
    (*tree)->lchild->lchild->rchild = NULL;
    (*tree)->lchild->rchild->lchild = NULL;
    (*tree)->lchild->rchild->rchild = NULL;
    (*tree)->rchild->lchild->lchild = NULL;
    (*tree)->rchild->lchild->rchild = NULL;
}

void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL)
    {
        InThread(p->lchild, pre);
        if (p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreatInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T != NULL)
    {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

ThreadNode *Firstnode(ThreadNode *p)
{
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}

ThreadNode *Nextnode(ThreadNode *p)
{
    if (p->rtag == 0)
    {
        return Firstnode(p->rchild);
    }
    else
    {
        return p->rchild;
    }
}

void InOrder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
    {
        cout << p->data << endl;
    }
}

int main()
{
    ThreadTree Tree;
    init(&Tree);

    CreatInThread(Tree);

    InOrder(Tree);

    system("pause");
}