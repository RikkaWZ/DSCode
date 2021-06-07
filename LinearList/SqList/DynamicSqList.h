#define InitSize 10
#define ElemType int

// 动态分配顺序表
typedef struct {
    ElemType *data;
    int MaxSize;
    int length;
} SqList;

void InitList(SqList &L) {
    L.data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    L.MaxSize = InitSize;
    L.length = 0;
}

void IncreaseSize(SqList &L, int len) {
    int *p = L.data;
    L.data = (ElemType *)malloc((L.MaxSize + len) * sizeof(ElemType));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}
