#define InitSize 50 //数组动态分配

typedef int ElemType;

typedef struct
{
    ElemType *data;
    int MaxSize, length;
} SqList;

// #define MaxSize 50 //数组静态分配

// typedef int ElemType;

// typedef struct
// {
//     ElemType data[MaxSize];
//     int length;
// } SqList;

int InitList(SqList &L);

int Length(SqList L);

bool ListInsert(SqList &L, int i, ElemType e);

bool ListDelet(SqList &L, int i, ElemType &e);

int LocateElem(SqList L, ElemType e);