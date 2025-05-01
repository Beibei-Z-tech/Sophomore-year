#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef int ArcType;
typedef int VertexType;
struct ArcNode {
    int adjvex;
    ArcType weight;
    ArcNode* nextarc;

    ArcNode(int a, ArcType w, ArcNode* n) : adjvex(a), weight(w), nextarc(n) {}
};
struct VNode {
    VertexType data;
    ArcNode* firstarc;
};
typedef VNode AdjList[100];
struct AdjGraph {
    AdjList vertices;
    int vexnum, arcnum;
};
void CreateGraph(AdjGraph& G) {
    G.vexnum = 4; 
    G.arcnum = 7; 
    for (int i = 0; i < G.vexnum; ++i) {
        G.vertices[i].data = i;
        G.vertices[i].firstarc = nullptr;
    }
    G.vertices[0].firstarc = new ArcNode(1, 1, nullptr);
    G.vertices[0].firstarc->nextarc = new ArcNode(2, 3, nullptr);
    G.vertices[0].firstarc->nextarc->nextarc = new ArcNode(3, 2, nullptr);
    G.vertices[1].firstarc = new ArcNode(0, 1, nullptr);
    G.vertices[1].firstarc->nextarc = new ArcNode(2, 9, nullptr);
    G.vertices[1].firstarc->nextarc->nextarc = new ArcNode(3, 5, nullptr);
    G.vertices[2].firstarc = new ArcNode(0, 3, nullptr);
    G.vertices[2].firstarc->nextarc = new ArcNode(1, 9, nullptr);
    G.vertices[2].firstarc->nextarc->nextarc = new ArcNode(3, 6, nullptr);
    G.vertices[3].firstarc = new ArcNode(0, 2, nullptr);
    G.vertices[3].firstarc->nextarc = new ArcNode(1, 5, nullptr);
    G.vertices[3].firstarc->nextarc->nextarc = new ArcNode(2, 6, nullptr);
}
ArcType GetWeight(const AdjGraph& G, int u, int v) {
    for (ArcNode* p = G.vertices[u].firstarc; p != nullptr; p = p->nextarc) {
        if (p->adjvex == v) {
            return p->weight;
        }
    }
    return -1; 
}
int GetFirstNeighbor(AdjGraph& G, int v) {
    if (G.vertices[v].firstarc != nullptr) {
        return G.vertices[v].firstarc->adjvex;
    }
    return -1; 
}

int GetNextNeighbor(AdjGraph& G, int v, int w) {
    ArcNode* p = G.vertices[v].firstarc;
    while (p != nullptr && p->adjvex != w) {
        p = p->nextarc;
    }
    if (p != nullptr && p->nextarc != nullptr) {
        return p->nextarc->adjvex;
    }
    return -1; 
}
void DFS(AdjGraph& G, int v, vector<bool>& visited) {
    visited[v] = true;
    cout << G.vertices[v].data << " ";
    for (int w = GetFirstNeighbor(G, v); w >= 0; w = GetNextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w, visited);
        }
    }
}
void DFSTraverse(AdjGraph& G) {
    vector<bool> visited(G.vexnum, false);
    for (int v = 0; v < G.vexnum; ++v) {
        if (!visited[v]) {
            DFS(G, v, visited);
        }
    }
}
int main() {
    AdjGraph G;
    CreateGraph(G);
    cout << "Depth First Search Traversal: ";
    DFSTraverse(G);
    cout << endl;
    return 0;
}
