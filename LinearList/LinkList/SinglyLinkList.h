#include <stdio.h>
#include <stdlib.h>
#define ElemType int

typedef struct SLNode {
    ElemType data;
    struct SLNode *next;
} SLNode, *SinglyLinkList;

/**
 * 初始化一个空的单链表，不带头结点
 */
bool InitListWOHead(SinglyLinkList &L) {
    L = NULL;
    return true;
}

/**
 * 初始化一个空的单链表，带头结点
 */
bool InitList(SinglyLinkList &L) {
    L = (SLNode *)malloc(sizeof(SLNode));
    if (L == NULL)
        // 内存不足，分配失败
        return false;
    L -> next = NULL;
    return true;
}

/**
 * 头插法建立单链表
 */
SinglyLinkList List_HeadInsert(SinglyLinkList &L) {
    SLNode *s;
    int x = 0;
    L = (SinglyLinkList)malloc(sizeof(SLNode));
    L -> next = NULL;
    while (x != 9999) {
        s = (SLNode*) malloc(sizeof(SLNode));
        s -> data = x;
        s -> next = L -> next;
        L -> next = s;
        scanf("%d", &x);
    }
    return L;
}
