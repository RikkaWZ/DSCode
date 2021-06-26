#include "ThreadNode.h"

/**
 * 线索二叉树
 */
typedef struct ThreadNode *ThreadTree;

/**
 * 辅助全局变量
 * 指向访问结点的前驱
 */
ThreadNode *pre = NULL;

/**
 * 访问一个结点
 */
void visit(ThreadNode *q) {
    if (q->lChild == NULL) {
        // 左子树为空，建立前驱线索
        q->lChild = pre;
        q->lTag = 1;
    }
    if (pre != NULL && pre->rChild == NULL) {
        // 建立前驱结点的后继线索
        pre->rChild = q;
        pre->rTag = 1;
    }
}

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
 * 后序遍历二叉树，边遍历边线索化
 */
void PostThread(ThreadTree T) {
    if (T != NULL) {
        PostThread(T->lChild);
        PostThread(T->rChild);
        visit(T);
    }
}

/**
 * 先序线索化二叉树
 */
void CreatePostThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) {
        PostThread(T);
        if (pre->rChild == NULL) {
            // 处理遍历的最后一个结点
            pre->rTag = 1;
        }
    }
}













