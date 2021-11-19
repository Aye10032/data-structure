# 2、线性表

## 2.1 顺序表

### 1、结构体

静态定义：

```c
#define MaxSize 50 //数组静态分配

typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
```

动态定义：

```c
#define InitSize 50 //数组动态分配

typedef int ElemType;

typedef struct
{
    ElemType *data;
    int MaxSize, length;
} SqList;
```

### 2、插入

数组逐项后移

## 2.2 链表

### 1、结构体

```c
typedef struct LNode //结点
{
    ElemType data;      //数据域
    struct LNode *next; //指针域
} LNode, *LinkList;
```

### 2、建立

头插法：

```c
s = (LNode *)malloc(sizeof(LNode));
s->data = x;
s->next = L->next;
L->next = s;
```

尾插法：

```C
s = (LNode *)malloc(sizeof(LNode));
s->data = x;
r->next = s; //r为尾结点
r = s;
```

