#define MaxVertexNum 100
#define VertexType int

/**
 * 邻接表法存储图
 */

/**
 * 边表结点
 */
typedef struct ArcNode {
    int adjVex; // 该弧指向顶点的位置
    struct ArcNode *next;  // 指向下一条弧的指针
    // InfoType info; // 网的边权值
} ArcNode;

/**
  * 顶点表结点
  */
typedef struct VNode {
    VertexType data;
    ArcNode *first; // 指向第一条依附此结点的弧的指针
} VNode, AdjList[MaxVertexNum];

/**
 * 邻接表
 */
typedef struct {
    AdjList vertices;
    int vexNum, arcNum;
} ALGraph;

/**
 * 求图中顶点 x 的第一个邻接点
 */
int FirstNeighbor(ALGraph G, int x) {
    if (G.vertices[x].first == NULL)
        return -1;
    else
        return G.vexNum[x].first->adjVex;
}

/**
 * y 是 x 的一个临界点，返回图中除 x 外的下一个邻接点
 */
int NextNeighbor(ALGraph G, int x, int y) {
    VNode v = G.vertices[x];
    ArcNode *a = v.first;
    while (a->adjVex != y)
        a = a->next;
    if (a->next == NULL)
        return -1;
    else
        return a->next->adjVex;
}






















