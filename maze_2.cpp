#include <iostream>
#include <vector>

using namespace std;

const int rows = 10;
const int cols = 10;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int map[10][10] = {
    { 9,9,9,9,9,9,9,9,9,9 },
    { 9,0,0,9,0,0,0,9,0,9 },
    { 9,0,0,9,0,0,0,9,0,9 },
    { 9,0,0,0,0,9,9,0,0,9 },
    { 9,0,9,9,9,0,0,0,0,9 },
    { 9,0,0,0,9,9,0,0,0,9 },
    { 9,0,9,0,0,0,9,0,9,9 },
    { 9,0,9,9,9,0,9,9,0,9 },
    { 9,9,0,0,0,0,0,0,0,9 },
    { 9,9,9,9,9,9,9,9,9,9 }
};

bool visited[rows][cols] = {false};

bool isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && map[x][y] == 0 && !visited[x][y];
}

bool findPath(int x, int y, int endX, int endY, vector<pair<int, int> > &path) {

    if (x == endX && y == endY) {
        path.push_back(make_pair(x, y));
        return true;
    }

    visited[x][y] = true;
    path.push_back(make_pair(x, y));

    for (int i = 0; i < 4; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isValid(nextX, nextY)) {
            if (findPath(nextX, nextY, endX, endY, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

int main() {

    vector<pair<int, int> > path1;
    fill(&visited[0][0], &visited[0][0] + rows * cols, false); 
    if (findPath(1, 1, 8, 8, path1)) {
        cout << "Path from (1,1) to (8,8):" << endl;
        for (vector<pair<int, int> >::const_iterator it = path1.begin(); it != path1.end(); ++it) {
            cout << "(" << it->first << "," << it->second << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found from (1,1) to (8,8)." << endl;
    }
    
    vector<pair<int, int> > path2;
    fill(&visited[0][0], &visited[0][0] + rows * cols, false);
    if (findPath(8, 8, 1, 1, path2)) {
        cout << "Path from (8,8) to (1,1):" << endl;
        for (vector<pair<int, int> >::const_iterator it = path2.begin(); it != path2.end(); ++it) {
            cout << "(" << it->first << "," << it->second << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found from (8,8) to (1,1)." << endl;
    }
    
    return 0;
}
