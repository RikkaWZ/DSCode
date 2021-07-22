#define ElemType int
#define MaxSize 10

typedef struct LinkQNode {
    ElemType data;
    struct LinkQNode *next;
} LinkQNode;