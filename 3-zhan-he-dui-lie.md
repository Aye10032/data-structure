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



队头出、队尾入



### 2、中缀转后缀

- **操作数**：直接加入表达式
- **界限符**
  - “(”：直接入栈
  - “)”：依次弹出运算符，直到“(”为止
- **运算符**
  - 依次弹出栈中优先级大于等于当前运算符的所有运算符
  - 碰到“(”或栈空停止
