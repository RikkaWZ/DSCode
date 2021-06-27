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
