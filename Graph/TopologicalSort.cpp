#include "ALGraph.h"
#include "../LinearList/Stack/SqStack.h"

/**
 * 拓扑排序
 */

int indegree[MaxVertexNum]; // 顶点的入度，需要初始化
int print[MaxVertexNum]; // 记录拓扑序列
SqStack S; // 辅助栈

bool TopoLogicalSort(ALGraph G) {
    InitStack(S);
    for (int i = 0; i < G.vexNum; i++)
        if (indegree[i] == 0)
            // 所有入度为 0 的顶点进栈
            Push(S, i);
    int count = 0;
    while (!IsEmpty(S)) {
        int i = 0;
        Pop(S, i);
        print[count++] = i;
        // 将所有 i 指向顶点的入度减 1，并且将入度为 0 的顶点压入栈
        for (ArcNode *p = G.vertices[i].first; p; p = p->next) {
            int v = p->adjVex;
            if (!(--indegree[v]))
                Push(S, v);
        }
    }
    if (count < G.vexNum)
        // 排序失败，有向图有回路
        return false;
    else
        return true;
}

