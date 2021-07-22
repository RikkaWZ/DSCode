#define ElemType int

typedef struct DNode {
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DNode;