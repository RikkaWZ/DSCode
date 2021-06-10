#include <stdio.h>
#include <stdlib.h>

#include "../Node/DNode.cpp"

typedef struct DNode *DLinkList;

void DeleteNextDNode(DLinkList &pNode);

/**
 * 双链表的初始化
 */
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode)); // 头结点
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

/**
 * 判断双链表是否为空
 */
bool Empty(DLinkList L) {
    if (L->next == NULL)
        return true;
    else
        return false;
}

/**
 * 结点之后插入结点
 */
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    if (p->next != NULL)
        // 要被插入的结点如果有后继结点需要修改其前驱
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

/**
 * 删除双链表
 */
void DestoryList(DLinkList &L) {
    // 循环删除各个数据结点
    while (L->next != NULL)
        DeleteNextDNode(L);
    free(L); // 删除头结点
    L = NULL; // 头指针指向 NULL
}

/**
 * 删除结点的后继结点
 */
bool DeleteNextDNode(DNode *p) {
    if (p == NULL)
        return false;
    DNode *q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}



















