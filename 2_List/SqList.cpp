#include "SqList.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

int InitList(SqList &L)
{
    L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
}

int Length(SqList L)
{
    return L.length;
}

bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length)
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