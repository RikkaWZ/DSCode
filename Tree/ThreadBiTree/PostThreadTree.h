#include "ThreadTree.h"

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
 * 后序线索化二叉树
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

/**
 * 找到结点的前驱结点
 */
ThreadNode *NextNode(ThreadNode *p) {
    // 怀疑王道的课这里讲错了
    if (p->rTag == 0) {
        // 有右孩子
        if (p->lTag == 0)
            return p->lChild;
        else
            return p->rChild;
    } else {
        // 没右孩子，返回后继线索
        return p->rChild;
    }
}