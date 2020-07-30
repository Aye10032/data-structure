#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"
using namespace std;

int main()
{
    SqList L;

    InitList(L);
    bool flag = ListInsert(L, 1, 1);
    printf("%b", flag);

    system("pause");
}