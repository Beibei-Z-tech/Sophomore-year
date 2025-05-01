#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
struct Graph {
    int V; 
    std::vector<std::vector<int> > adjList; 

    Graph(int V) : V(V), adjList(V) {} 

    void addEdge(int src, int dest) { 
        adjList[src].push_back(dest);
    }
    void topologicalSort() {
        std::stack<int> stack;
        std::vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
            if (!visited[i])
                topologicalSortUtil(i, visited, stack);
        while (!stack.empty()) {
            std::cout << stack.top() << " ";
            stack.pop();
        }
    }

    void topologicalSortUtil(int v, std::vector<bool>& visited, std::stack<int>& stack) {
        visited[v] = true;
        for (int i = 0; i < adjList[v].size(); ++i) {
            int neighbor = adjList[v][i];
            if (!visited[neighbor])
                topologicalSortUtil(neighbor, visited, stack);
        }

        stack.push(v);
    }
};

int main() {
    Graph g(9);
    g.addEdge(0, 1); // C1 -> C2
    g.addEdge(0, 2); // C1 -> C3
    g.addEdge(1, 3); // C2 -> C4
    g.addEdge(1, 4); // C2 -> C5
    g.addEdge(2, 3); // C3 -> C4
    g.addEdge(3, 5); // C4 -> C6
    g.addEdge(3, 6); // C4 -> C7
    g.addEdge(4, 5); // C5 -> C6
    g.addEdge(4, 6); // C5 -> C7
    g.addEdge(7, 8); // C8 -> C9

    g.topologicalSort();
    return 0;
}

