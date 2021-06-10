#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct SNode {
    ElemType data;
    struct SNode *next;
} SNode, *SLinkList;

bool InsertNextNode(SNode *pNode, int e);

SNode *GetElem(SLinkList &pNode, int i);

/**
 * 初始化一个空的单链表，不带头结点
 */
bool InitListWOHead(SLinkList &L) {
    L = NULL;
    return true;
}

/**
 * 初始化一个空的单链表，带头结点
 */
bool InitList(SLinkList &L) {
    L = (SNode *) malloc(sizeof(SNode));
    if (L == NULL)
        // 内存不足，分配失败
        return false;
    L->next = NULL;
    return true;
}

/**
 * 头插法建立单链表
 */
SLinkList List_HeadInsert(SLinkList &L) {
    SNode *s;
    int x = 0;
    L = (SLinkList) malloc(sizeof(SNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999) {
        s = (SNode *) malloc(sizeof(SNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

/**
 * 尾插法建立单链表
 */
SLinkList List_TailInsert(SLinkList &L) {
    int x = 0;
    L = (SLinkList) malloc(sizeof(SNode));
    SNode *s;
    SNode *r = L;
    scanf("%d", &x);
    while (x != 9999) {
        s = (SNode *) malloc(sizeof(SNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

/**
 * 按位序插入（带头节点）
 * @param i 位序
 * @param e 要插入的值
 */
bool ListInsert(SLinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    SNode *p = GetElem(L, i - 1);
    return InsertNextNode(p, e);
}

/**
 * 按位序插入（不带头节点）
 * @param i 位序
 * @param e 要插入的值
 */
bool ListInsertWOHead(SLinkList &L, int i, ElemType e) {
    if (i < 1)
        return false;
    if (i == 1) {
        // 插入第一个节点的操作和其他节点操作逻辑不同
        SNode *s = (SNode *) malloc(sizeof(SNode));
        s->data = e;
        s->next = L;
        L = s; // 头指针指向新节点
        return true;
    }
    SNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e);
}

/**
 * 指定结点的后插操作
 * @param p 指定的结点
 * @param e 要插入的值
 */
bool InsertNextNode(SNode *p, ElemType e) {
    if (p == NULL)
        return false;
    SNode *s = (SNode *) malloc(sizeof(SNode));
    if (s == NULL)
        // 内存分配失败
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

/**
 * 指定结点的前插操作
 * @param p 指定的结点
 * @param e 要插入的值
 */
bool InsertPriorNode(SNode *p, ElemType e) {
    if (p == NULL)
        return false;
    SNode *s = (SNode *) malloc(sizeof(SNode));
    if (s == NULL)
        // 内存分配失败
        return false;
    // 先后插
    s->next = p->next;
    p->next = s;
    // 再互换两个结点的值即可
    s->data = p->data;
    p->data = e;
    return true;
}

/**
 * 按位序删除
 * @param L 链表
 * @param i 位序
 * @param e 删除结点的值
 */
bool ListDelete(SLinkList &L, int i, ElemType &e) {
    if (i < 1)
        return false;
    SNode *p = GetElem(L, i - 1);
    if (p == NULL)
        // i 值不合法
        return false;
    if (p->next == NULL)
        // 第 i - 1 个结点后已无其他结点
        return false;
    SNode *q = p->next; // 被删除结点
    e = q->data; // 用 e 返回删除结点的值
    p->next = q->next; // 断链
    free(q);
    return true;
}

/**
 * 指定结点的删除
 * @param p 要删除结点的前驱结点，其不能是最后一个结点
 */
bool DeleteNode(SNode *p) {
    if (p == NULL)
        return false;
    SNode *q = p->next; // 被删除结点
    p->data = p->next->data; // 用 e 返回删除结点的值
    p->next = q->next; // 断链
    free(q);
    return true;
}

/**
 * 按位查找，返回第 i 个元素
 * @param L 链表
 * @param i  位序
 */
SNode *GetElem(SLinkList L, int i) {
    if (i < 0)
        return NULL;
    SNode *p;
    int j = 0;
    p = L;
    // 循环找到第 i 个结点
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/**
 * 按值查找
 * @param L 链表
 * @param e 要查询的值
 */
SNode *LocateElem(SLinkList L, ElemType e) {
    SNode *p = L->next;
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

/**
 * 求链表的长度
 * @param L 链表
 */
int Length(SLinkList L) {
    int len = 0;
    SNode *p = L;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}






















