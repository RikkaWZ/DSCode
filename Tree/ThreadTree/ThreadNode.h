typedef int ElemType;

/**
 * 线索二叉树结点
 */
typedef struct ThreadNode {
    ElemType data;
    /*
     * 线索标志为 0，表示孩子
     * 线索标志为 1，表示线索
     */
    int lTag;
    struct ThreadNode *lChild;
    int rTag;
    struct ThreadNode *rChild;
} ThreadNode;
