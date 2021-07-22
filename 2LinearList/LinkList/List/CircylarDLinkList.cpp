#include <stdlib.h>

#include "../Node/DNode.cpp"

typedef DNode *CDLinkList;

/**
 * 初始化一个空的循环链表
 */
bool InitList(CDLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL)
        // 内存不足，分配失败
        return false;
    L->prior = L;
    L->next = L; // next 指向头结点
    return true;
}

/**
 * 判断循环单链表是否为空
 */
bool Empty(CDLinkList L) {
    if (L->next == L)
        return true;
    else
        return false;
}

/**
 * 判断结点是否为循环单链表的表尾结点
 */
bool isTail(CDLinkList L, DNode *p) {
    if (p->next == L)
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
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

/**
 * 删除结点的后继结点
 */
bool DeleteNextDNode(DNode *p) {
    if (p == NULL)
        return false;
    DNode *q = p->next;
    // 后继结点肯定不是 NULL，放心操作
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}
