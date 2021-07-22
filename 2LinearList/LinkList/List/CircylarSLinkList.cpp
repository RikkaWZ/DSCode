#include <stdlib.h>

#include "../Node/LNode.cpp"

#define ElemType int

typedef LNode *CDLinkList;

/**
 * 初始化一个空的循环链表
 */
bool InitList(CDLinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL)
        // 内存不足，分配失败
        return false;
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
bool isTail(CDLinkList L, LNode *p) {
    if (p->next == L)
        return true;
    else
        return false;
}
