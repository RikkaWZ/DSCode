#include "stdlib.h"
#include "ALGraph.h"

/**
 * 王道 6.2.7.4
 * 图的邻接表表示转换为邻接矩阵表示
 */
void Convert(ALGraph &G, int arcs[MaxVertexNum][MaxVertexNum]) {
    for (int i = 0; i < G.vexNum; i++) {
        ArcNode *p = G.vertices[i].first; // 取出顶点 i 的第一条出边
        while (p != NULL) {
            arcs[i][p->adjVex] = 1;
            p = p->next;
        }
    }
}