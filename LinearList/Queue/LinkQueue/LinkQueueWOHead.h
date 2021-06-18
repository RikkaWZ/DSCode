#include "LinkQueueNode.h"
#include "stdlib.h"

/**
 * 队列的链式实现（不带头结点）
 */
typedef struct {
    LinkQNode *front;
    LinkQNode *rear;
} LinkQueueWOHead;

/**
 * 初始化队列
 */
void InitQueueWOHead(LinkQueueWOHead &Q) {
    // 初始化时，两个指针都指向 NULL
    Q.front = NULL;
    Q.rear = NULL;
}

/**
 * 判断队列是否为空
 */
bool IsEmpty(LinkQueueWOHead Q) {
    if (Q.front == NULL)
        return true;
    else
        return false;
}

/**
 * 入队
 */
void EnQueue(LinkQueueWOHead &Q, ElemType x) {
    LinkQNode *s = (LinkQNode *) malloc(sizeof(LinkQNode));
    s->data = x;
    s->next = NULL;
    if (Q.front == NULL) {
        // 空队列中插入第一个元素
        Q.front = s;
        Q.rear = s;
    } else {
        Q.rear->next = s;
        Q.rear = s;
    }
}

/**
 * 出队
 */
bool DeQueue(LinkQueueWOHead &Q, ElemType &x) {
    if (IsEmpty(Q))
        return false;
    LinkQNode *p = Q.front;
    x = p->next; // 返回队头元素
    Q.front = p->next;
    if (Q.rear == p) {
        // 最后一个结点出队
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}



















