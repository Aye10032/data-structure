#include "SqList.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int InitList(SqList &L)
{
    L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);

    return 0;
}

int Length(SqList L)
{
    return L.length;
}

bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    if (L.length >= L.MaxSize)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelet(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

void printList(SqList L)
{
    cout << "\n[";
    for (int j = 0; j < L.length; j++)
    {
        cout << L.data[j] << " ";
    }
    cout << "]" << endl;
}

int main()
{
    SqList L;

    InitList(L);
    for (int i = 1; i <= 10; i++)
    {
        bool flag = ListInsert(L, i, i);
    }
    printList(L);

    ListInsert(L, 2, 10);
    bool flag = ListInsert(L, 1, 1);
    cout << flag;
    printList(L);
    
    int a;
    ListDelet(L, 3, a);
    cout << a;
    printList(L);

    system("pause");
}