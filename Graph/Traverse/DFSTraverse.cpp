#include "../MGraph.h"

/**
 * 深度优先遍历
 */

bool visited[MaxVertexNum]; // 访问标记数组

/**
 * 从顶点 v 开始深度优先遍历图
 */
void DFS(MGraph G, int v) {
    visited[v] = true;
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        if (!visited[w])
            DFS(G, w);
}

/**
 * 对图进行深度优先遍历
 */
void DFSTraverse(MGraph G) {
    for (int v = 0; v < G.vexNum; v++)
        visited[v] = false;
    for (int v = 0; v < G.vexNum; v++)
        if (!visited[v])
            DFS(G, v);
}