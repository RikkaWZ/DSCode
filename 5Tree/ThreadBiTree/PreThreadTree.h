#include "ThreadTree.h"

/**
 * 先序遍历二叉树，边遍历边线索化
 */
void PreThread(ThreadTree T) {
    if (T != NULL) {
        visit(T);
        PreThread(T->lChild);
        PreThread(T->rChild);
    }
}

/**
 * 先序线索化二叉树
 */
void CreatePreThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {
        PreThread(T);
        if (pre->rChild == NULL) {
            // 处理遍历的最后一个结点
            pre->rTag = 1;
        }
    }
}

/**
 * 找到结点的前驱结点
 */
ThreadNode *PreNode(ThreadNode *p) {
    if (p->ltag == 0) {
        if (p->rtag == 0)
            return p->rchild;
        else
            return	p->lchild;
    }
    else
        return p->lchild;
}