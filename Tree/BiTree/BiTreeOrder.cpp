#include "stdio.h"
#include "BiTree.h"

/**
 * 二叉树的遍历
 */

/**
 * 遍历一个结点
 */
void visit(BiTNode* N) {
    printf("%d ", (*N).data.value);
}

/**
 * 先序遍历
 */
void PreOrder(BiTree T) {
    if (T != NULL) {
        visit(T);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}

/**
 * 中序遍历
 */
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lChild);
        visit(T);
        InOrder(T->rChild);
    }
}

/**
 * 后序遍历
 */
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lChild);
        PostOrder(T->rChild);
        visit(T);
    }
}