#include "stdlib.h"
#include "BiTNode.h"

/**
 * 二叉树
 */
typedef struct BiTNode *BiTree;

/**
 * 初始化一棵带根结点的树
 */
void InitBiTreeWithRoot(BiTree &T) {
    BiTree root = (BiTree) malloc(sizeof(BiTNode));
    root->data = {1};
    root->lChild = NULL;
    root->rChild = NULL;
    T = root;
}