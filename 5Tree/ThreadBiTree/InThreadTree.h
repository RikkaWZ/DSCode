#include "ThreadTree.h"

/**
 * 中序线索二叉树
 */

/**
 * 中序遍历二叉树，边遍历边线索化
 */
void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T->lChild);
        visit(T);
        InThread(T->rChild);
    }
}

/**
 * 中序线索化二叉树
 */
void CreateInThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {
        InThread(T);
        if (pre->rChild == NULL) {
            // 处理遍历的最后一个结点
            pre->rTag = 1;
        }
    }
}

/**
 * 找到子树中第一个被中序遍历的结点
 */
ThreadNode *FirstNode(ThreadNode *p) {
    // 循环找到最左下的结点
    while (p->lTag == 0)
        p = p->lChild;
    return p;
}

/**
 * 找到子树中最后一个被中序遍历的结点
 */
ThreadNode *LastNode(ThreadNode *p) {
    // 循环找到最右下的结点
    while (p->rTag == 0)
        p = p->rChild;
    return p;
}

/**
 * 找到结点的后继结点
 */
ThreadNode *NextNode(ThreadNode *p) {
    // 右子树中的最左下结点
    if (p->rTag == 0)
        return FirstNode(p->rChild);
    else
        return p->rChild;
}

/**
 * 找到结点的前驱结点
 */
ThreadNode *PreNode(ThreadNode *p) {
    // 右子树中的最右下结点
    if (p->lTag == 0)
        return LastNode(p->lChild);
    else
        return p->lChild;
}

/**
 * 中序遍历（非递归算法）
 */
void InOrder(ThreadTree T) {
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
        visit(p);
}

/**
 * 逆向中序遍历（非递归算法）
 */
void RevInOrder(ThreadTree T) {
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p))
        visit(p);
}












