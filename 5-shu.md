# 5、树

### 1、树的性质

- 节点数=所有节点的度数和+1

- 度为m的树第i层的节点数至多有：$$m^{i-1}$$

- 高为h，m叉树至多的节点数：

$$
\sum_{i=0}^{h}m^{i-1}=\frac{m^{h}-1}{m-1}
$$

- n个节点的m叉树最小高度为：$$\log_{m}[n(m-1)+1]$$向上取整

### 2、二叉树

- $$n_{0}=n_{2}+1$$
- 第K层的节点数至多有：$$2^{k-1}$$

顺序存储（完全二叉树）

![完全二叉树](.gitbook/assests/完全二叉树.png)

```c
struct TreeNode {
    ElemType value; //结点中的数据元素
    bool isEmpty; //结点是否为空
};

TreeNode t [MaxSize]; //按照完全二叉树的顺序存储
```

链式存储

```c
typedef struct BiTNode{
    ELemType data; //数据域
    struct BiTNode *lchild, *rchild; //左、右孩子指针
}BiTNode ,*BiTree;
```

初始化

```c
//定义一棵空树
BiTree root = NULL;
//插入根节点
root = (BiTree) malloc(sizeof(BiTNode));
root-> data = {1};
root-> lchild = NULL;
root-> rchild = NULL;
//插入新结点
BiTNode * p = (BiTNode *) malloc(sizeof(BiTNode));
p->data = {2};
p-> lchild = NULL;
p-> rchild = NULL;
root->lchild = p; //作为根节点的左孩子

```

先序遍历（根-左-右）

```c
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T); //访问根结点
        PreOrder(T->lchild); //递归遍历左子树
        PreOrder(T- ->rchild); //递归遍历右子树
    }
}
```

中序遍历（左-根-右）

```c
void PreOrder(BiTree T){
    if(T!=NULL){
        PreOrder(T->lchild); //递归遍历左子树
        visit(T); //访问根结点
        PreOrder(T- ->rchild); //递归遍历右子树
    }
}
```

后序遍历（左-右-根）

```c
void PreOrder(BiTree T){
    if(T!=NULL){
        PreOrder(T->lchild); //递归遍历左子树
        PreOrder(T- ->rchild); //递归遍历右子树
        visit(T); //访问根结点
    }
}
```

层序遍历

- 将根节点入队
- 队列非空
  - 将队头出队，访问该节点
  - 将该节点的左、右孩子依次插入队尾
- 重复直至队列为空

```c
//链式队列结点
typedef struct LinkNode{
    BiTNode * data; //保存的是节点的指针
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear; //队头队尾
}LinkQueue;

//层序遍历
void Level0rder(BiTree T){
    LinkQueue Q;
    InitQueue(Q); 					//初始化辅助队列
    BiTree p;
    EnQueue(Q,T); 					//将根结点入队
    while(!IsEmpty(Q)){ 			//队列不空则循环
        DeQueue(Q，p); 			   //队头结点出队
        visit(p); 					//访问出队结点
        if(p->lchild != NULL)
        	EnQueue(Q, p->lchild);  //左孩子入队
        if(p->rchild != NULL)
        	EnQueue(Q, p->rchild);  //右孩子入队
    }
}
```

线索二叉树

![中序线索二叉树](.gitbook/assests/中序线索二叉树.png)

- 左指针指向中序前驱
- 右指针指向中序后继

```c
//全局变量pre,指向当前访问结点的中(前、后)序前驱
ThreadNode *pre=NULL;

typedef struct BiTNode{
    ELemType data; //数据域
    struct BiTNode *lchild, *rchild; //左、右孩子指针
    int ltag, rtag; //左、 右线索标志：0表示孩子，1表示线索
}BiTNode ,*BiTree;
```

中序线索化

```c
void visit(ThreadNode *q) {
    if(q->lchild == NULL) { //当前节点左子树为空,建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre != NULL && pre->rchild == NULL) {
        pre->rchild = q; //前驱结点的右子树为空，建立后继线索
        pre->rtag = 1;
    }
    pre=q;
}
```

前后序类似，注意

- 最后再修改一次per的后继节点为null
- 遍历时判断左右子树是孩子还是线索
