#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef int ElemType;

typedef struct LNode //结点
{
    ElemType data;      //数据域
    struct LNode *next; //指针域
} LNode, *LinkList;

// 头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int n, x;

    // 创建头节点
    L = (LinkList)malloc(sizeof(LNode));
    L->next == NULL;

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cout << "new node:" << endl;
        cin >> x;
    }
    return L;
}

// 尾插法
LinkList List_TailInsert(LinkList &L)
{
    int n, x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cout << "new node:" << endl;
    }
    r->next = NULL;
    return L;
}

//按序号查找
LNode *getElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next; //头结点的下一个结点

    if (i == 0)
    {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }

    while (p != NULL && j < i) //下一个结点不为空（即链表没有结束），同时没有到目标位置
    {
        p = p->next;
        j++;
    }

    return p;
}

//按值查找
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p->data != e && p != NULL)
    {
        p = p->next;
    }

    return p;
}

// 插入节点
int InsertElem(LinkList L, int i, int x)
{
    LNode *p, *s;
    p = getElem(L, i - 1);
    s->data = x;
    s->next = p->next;
    p->next = s;

    return 0;
}

//删除结点
int DeletElem(LinkList &L, int i)
{
    LNode *p, *q;
    p = getElem(L, i - 1);
    q = p->next;
    p->next = q->next;
    free(q);

    return 0;
}

int getMax(LinkList L)
{
    int max, min;
    LNode *p = L->next;

    max, min = p->data;

    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }

    return max;
}

void printlist(LinkList L)
{
    LNode *p = L->next;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{

    LinkList L;
    // List_HeadInsert(L);
    List_TailInsert(L);

    printlist(L);

    LNode *s = getElem(L, 3);
    cout << "No.3 is: " << s->data << endl;

    // s = LocateElem(L, 3);
    // cout << "3 is at" << s->data << endl;

    InsertElem(L, 3, 10);
    printlist(L);

    DeletElem(L, 2);
    printlist(L);

    cout << getMax(L) << endl;

    system("pause");
}