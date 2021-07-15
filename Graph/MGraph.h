#define MaxVertexNum 100
// #define INFINITY 25555? 表示网的时候用

/**
 * 邻接矩阵法存储图
 */
typedef struct {
    char Vex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexNum; // 当前顶点数
    int arcNum; // 当前弧线数
} MGraph;

/**
 * 求图中顶点 x 的第一个邻接点
 */
int FirstNeighbor(MGraph G, int x) {
    for (int i = 0; i < MaxVertexNum; i++)
        if (G.Edge[x][i] == 1)
            return i;
    return -1;
}

/**
 * y 是 x 的一个临界点，返回图中除 x 外的下一个邻接点
 */
int NextNeighbor(MGraph G, int x, int y) {
    for (int i = x + 1; i < MaxVertexNum; i++)
        if (G.Edge[x][i] == 1)
            return i;
    return -1;
}