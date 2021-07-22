#include "MGraph.h"
#include "../3SnQ/Queue/SqQueue.h"

/**
 * 广度优先遍历求最短路径
 */

int d[MaxVertexNum]; // 记录各顶点到原始顶点最短路径的长度
int path[MaxVertexNum]; // 记录每个顶点在最短路径上的直接前驱
bool visited[MaxVertexNum]; // 访问标记数组
SqQueue Q; // 辅助队列

/**
 * 从顶点 u 开始广度优先遍历图
 */
void BFSMinPath(MGraph G, int u) {
    for (int i = 0; i < G.vexNum; i++) {
        d[i] = INFINITY;
        path[i] = -1;
    }
    d[u] = 0;
    InitQueue(Q);
    visited[u] = true;
    EnQueue(Q, u);
    while (!IsEmpty(Q)) {
        DeQueue(Q, u);
        // 遍历 u 所有邻接点
        for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
            if (!visited[w]) {
                d[w] = d[u] + 1;
                path[w] = u;
                visited[w] = true;
                EnQueue(Q, w);
            }
    }
}
