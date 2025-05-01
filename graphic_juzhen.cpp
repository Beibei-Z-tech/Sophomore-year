#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;

class Graph{
private:
    vector<int> vertices;
    vector<vector<int> > adjMatrix; 
public:
    Graph(int n){
        for (int i=0;i<n;i++){
            vertices.push_back(i);
        }
        adjMatrix.resize(n, vector<int>(n, INF)); 
        for (int i=0;i<n;i++){
            adjMatrix[i][i]=0;
        }
    }
    void addEdge(int u,int v,int weight){
        adjMatrix[u][v] = weight;
    }
    void printVertices(){
        cout << "顶点表: ";
        for (size_t i=0;i<vertices.size();i++){
            cout << vertices[i] << " ";
        }
        cout << endl;
    }
    void printAdjMatrix(){
        cout << "邻接矩阵:" << endl;
        for (size_t i=0;i<adjMatrix.size();i++){
            for (size_t j=0;j<adjMatrix[i].size();j++){
                if (adjMatrix[i][j] == INF)
                    cout << "∞"
                            << " ";
                else
                    cout<<adjMatrix[i][j]<<" ";
            }
            cout << endl;
        }
    }
    int outDegree(int v){
        int count = 0;
        for (size_t i=0;i<adjMatrix.size();i++){
            if (adjMatrix[v][i]!=INF && adjMatrix[v][i]!=0){
                count++;
            }
        }
        return count;
    }
    int firstAdjacentVertex(int v){
        for (size_t i=0;i<adjMatrix.size();i++){
            if (adjMatrix[v][i]!=INF&&adjMatrix[v][i]!=0){
                return i;
            }
        }
        return -1; 
    }
    int nextAdjacentVertex(int v,int current){
        for (size_t i=current+1;i<adjMatrix.size();i++){
            if (adjMatrix[v][i]!=INF&&adjMatrix[v][i]!=0){
                return i;
            }
        }
        return -1; 
    }
};
int main(){
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(0, 3, 9);
    g.addEdge(1, 0, 4);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 0, 3);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 2, 8);
    g.addEdge(3, 1, 7);
    g.printVertices();
    g.printAdjMatrix();
    cout << "顶点1的出度: "<<g.outDegree(1)<<endl;
    int firstAdj = g.firstAdjacentVertex(2);
    if (firstAdj != -1) {
        cout<<"顶点2的第一个邻接顶点下标: "<<firstAdj<<endl;
    } else {
        cout<<"顶点2无邻接顶点"<<endl;
    }
    int nextAdj=g.nextAdjacentVertex(2, firstAdj);
    if (nextAdj!=-1){
        cout<<"顶点2的邻接顶点"<<firstAdj<<"的下一个邻接顶点下标: " <<nextAdj<<endl;
    } else {
        cout<<"顶点2的邻接顶点"<<firstAdj<<"无下一个邻接顶点"<<endl;
    }
    return 0;
}