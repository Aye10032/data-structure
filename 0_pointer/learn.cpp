#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    int i = 0;

    printf("%lu\n", sizeof(i));
    printf("0x%x\n", &i); //16进制输出

    printf("%lu\n", sizeof(&i));
    printf("%p\n", &i); //地址输出

    // 相邻变量的地址
    cout << "-----------------" << endl;
    int a = 0;
    int b = 9;
    printf("%p\n", &a);
    printf("%p\n", &b);

    // 指针变量
    int *p = &i;
    // int *p, q; p为指针，q为整形

    system("pause");
}