#define ElemType int
#define MaxSize 10

/**
 * 共享栈
 * 两个栈同时共享一片内存
 */
typedef struct {
    ElemType data[MaxSize];
    int top0;
    int top1;
} ShStack;

/**
 * 初始化栈
 */
void InitStack(ShStack &S) {
    S.top0 = -1; // 入栈时累加
    S.top1 = MaxSize; // 入栈时累减
}

/**
 * 判断栈是否满
 */
bool Full(ShStack S) {
    if (S.top0 + 1 == S.top1)
        return true;
    else
        return false;
}

