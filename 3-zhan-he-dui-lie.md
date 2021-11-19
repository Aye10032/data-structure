# 3、栈和队列

## 3.1 栈

### 1、构造

顺序实现

```C
typedef struct
{
    ElemType data[MaxSize];
    int top;
} Stack;
```

链式实现

```c
typedef struct Linknode
{
    ElemType data;
    struct Linknode *next;
} *LiStack;
```

## 3.2 队列

### 1、构造

```c
typedef struct
{
    ElemType data[MaxSize];
    int front, rear; //队头和队尾指针
} SqQueue;
```

