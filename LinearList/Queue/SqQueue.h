#define ElemType int
#define MaxSize 10

/**
 * 顺序队列（环状）
 * 废弃一个空间区分队满和队空
 */
typedef struct {
    ElemType data[MaxSize];
    int front;
    int rear;
} SqQueue;

/**
 * 初始化队列
 */
void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

/**
 * 判断队列是否为空
 */
bool IsEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

/**
 * 入队
 */
bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        // 队满
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize; // 环状
    return true;
}

/**
 * 出队
 */
bool DeQueue(SqQueue &Q, ElemType &x) {
    if (QueueEmpty(Q))
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

/**
 * 获得队头元素的值
 */
bool GetHead(SqQueue &Q, ElemType &x) {
    if (QueueEmpty(Q))
        return false;
    x = Q.data[Q.front];
    return true;
}








