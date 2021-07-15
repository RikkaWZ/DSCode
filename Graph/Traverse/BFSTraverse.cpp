#include "../MGraph.h"
#include "../../LinearList/Queue/SqQueue.h"

/**
 * 广度优先遍历
 */

bool visited[MaxVertexNum]; // 访问标记数组
SqQueue Q; // 辅助队列

/**
 * 从顶点 v 开始广度优先遍历图
 */
void BFS(MGraph G, int v) {
    visited[v] = true;
    EnQueue(Q, v);
    while (!IsEmpty(Q)) {
        DeQueue(Q, v);
        // 遍历 v 所有邻接点
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
            if (!visited[w]) {
                visited[w] = true;
                EnQueue(Q, w);
            }
    }
}

/**
 * 对图进行广度优先遍历
 */
void BFSTraverse(MGraph G) {
    for (int i = 0; i < G.vexNum; i++)
        visited[i] = false;
    InitQueue(Q);
    for (int i = 0; i < G.vexNum; i++)
        if (!visited[i])
            BFS(G, i);
}

