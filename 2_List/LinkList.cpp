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

int main()
{

    LinkList L;
    // List_HeadInsert(L);
    List_TailInsert(L);

    system("pause");
}