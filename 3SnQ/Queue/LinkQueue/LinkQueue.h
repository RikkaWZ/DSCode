#include "LinkQueueNode.h"
#include "stdlib.h"

/**
 * 队列的链式实现（带头结点）
 */
typedef struct {
    LinkQNode *front;
    LinkQNode *rear;
} LinkQueue;

/**
 * 初始化队列
 */
void InitQueue(LinkQueue &Q) {
    // 初始化时，两个指针都指向头结点
    Q.front = Q.rear = (LinkQNode *) malloc(sizeof(LinkQNode));
    Q.front -> next = NULL;
}

/**
 * 判断队列是否为空
 */
bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

/**
 * 入队
 */
void EnQueue(LinkQueue &Q, ElemType x) {
    LinkQNode *s = (LinkQNode *) malloc(sizeof(LinkQNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

/**
 * 出队
 */
bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (IsEmpty(Q))
        return false;
    LinkQNode *p = Q.front->next;
    x = p->next; // 返回队头元素
    Q.front->next = p->next;
    if (Q.rear == p)
        // 最后一个结点出队
        Q.rear = Q.front;
    free(p);
    return true;
}






















