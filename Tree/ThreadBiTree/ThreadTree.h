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













