#include <iostream>
#include <stdlib.h>
#include <string.h>
#define MaxSize 50

using namespace std;

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int top;
} Stack;

//初始化
void InitStack(Stack &s)
{
    s.top = -1; //初始化栈顶指针
}

//判断栈空
bool StackEmpty(Stack s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//进栈
bool Push(Stack &s, ElemType e){
    if (s.top == MaxSize -1) //栈满
    {
        return false;
    }else
    {
        s.data[++s.top] = e;
        return true;
    }
}

int main()
{
    Stack s;
    InitStack(s);

    cout << StackEmpty(s) << endl;

    Push(s, 1);

    cout << StackEmpty(s) << endl;

    system("pause");
}
