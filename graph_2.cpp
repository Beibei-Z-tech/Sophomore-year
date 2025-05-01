#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = INT_MAX; 
const int V = 4;
int graph[V][V] = {
    {0, 1, 3, 0},
    {0, 0, 5, 2}, 
    {9, 6, 0, 8}, 
    {0, 4, 0, 0}  
};
void BFS(int start, vector<bool>& visited) {
    queue<int> q; 
    visited[start] = true; 
    q.push(start);  
    while (!q.empty()) {
        int v = q.front();    
        q.pop();             
        cout << v << " ";  
        for (int i = 0; i < V; ++i) {
            if (graph[v][i] != 0 && !visited[i]) { 
                visited[i] = true;         
                q.push(i);                      
            }
        }
    }
    
    cout << endl;
}

int main() {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            cout << "Starting BFS from vertex " << i << ":" << endl;
            BFS(i, visited);
        }
    }
    return 0;
}
