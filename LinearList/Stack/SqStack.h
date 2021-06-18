#define ElemType int
#define MaxSize 10

/**
 * 顺序栈
 */
typedef struct {
    ElemType data[MaxSize];
    int top; // 栈顶指针，这里表示的是已有结点的最后一位
} SqStack;

/**
 * 初始化栈
 */
void InitStack(SqStack &S) {
    S.top = -1;
}

/**
 * 新元素入栈
 */
bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize -1)
        // 栈满
        return false;
    S.data[++S.top] = x;
    return true;
}

/**
 * 出栈
 */
bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1)
        // 栈空
        return false;
    x = S.data[S.top--]; // 只是逻辑删除，内存中仍然存在
    return true;
}

/**
 * 读栈顶元素
 */
bool GetTop(SqStack &S, ElemType &x) {
    if (S.top == -1)
        // 栈空
        return false;
    x = S.data[S.top];
    return true;
}

/**
 * 判断栈是否满
 */
bool Full(SqStack S) {
    if (S.top == MaxSize - 1)
        return true;
    else
        return false;
}




















