struct ElemType {
    int value;
};

/**
 * 二叉树链式存储结点
 */
typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lChild; // 左孩子
    struct BiTNode *rChild; // 右孩子
} BiTNode;