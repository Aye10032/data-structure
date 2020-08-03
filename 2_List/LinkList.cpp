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

    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cout << "new node:" << endl;
        cin >> x;
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

    while (p && j < i) //下一个结点不为空（即链表没有结束），同时没有到目标位置
    {
        p = p->next;
        j++;
    }

    return p;
}

int main()
{

    LinkList L;
    // List_HeadInsert(L);
    List_TailInsert(L);

    LNode *s = getElem(L, 3);
    cout << "No.3 is: " << s->data << endl;

    system("pause");
}