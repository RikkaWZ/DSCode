#define ElemType int
#define MaxSize 10

/**
 * 链栈
 */
typedef struct LinkStackNode {
    ElemType data;
    struct LinkStackNode *next;
} *LinkStack;