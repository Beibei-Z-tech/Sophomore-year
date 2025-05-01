#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Point {
    int x, y;
};

bool isValid(int x, int y, const vector<vector<int> > &maze, vector<vector<bool> > &visited) {
    return (x >= 0) && (x < maze.size()) && (y >= 0) && (y < maze[0].size()) 
           && maze[x][y] == 0 && !visited[x][y];
}

void printPath(stack<Point>& path) {
    vector<Point> pathVec;
    while (!path.empty()) {
        pathVec.push_back(path.top());
        path.pop();
    }
    for (vector<Point>::reverse_iterator it = pathVec.rbegin(); it != pathVec.rend(); ++it) {
        cout << "(" << it->x << "," << it->y << ") ";
    }
    cout << endl;
}

bool findPath(Point start, Point exit, vector<vector<int> >& maze) {
    vector<vector<bool> > visited(maze.size(), vector<bool>(maze[0].size(), false));
    stack<Point> pathStack;
    stack<Point> stack;
    stack.push(start);
    visited[start.x][start.y] = true;

    while (!stack.empty()) {
        Point current = stack.top();
        stack.pop();

        if (current.x == exit.x && current.y == exit.y) {
            while (!pathStack.empty()) {
                stack.push(pathStack.top());
                pathStack.pop();
            }
            stack.push(current);
            printPath(stack);
            return true;
        }

        const int dx[] = {-1, 0, 1, 0}; 
        const int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; ++i) {
            int nextX = current.x + dx[i];
            int nextY = current.y + dy[i];

            if (isValid(nextX, nextY, maze, visited)) {
                stack.push((Point){nextX, nextY});
                pathStack.push(current);
                visited[nextX][nextY] = true;
            }
        }
    }
    return false;
}

int main() {
    const int rows = 10;
    const int cols = 10;
    vector<vector<int> > maze(rows, vector<int>(cols));
    
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

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            maze[i][j] = map[i][j];
        }
    }

    // 测试样例1
    Point start1 = {1, 1};
    Point exit1 = {8, 8};
    cout << "Path from (1,1) to (8,8): ";
    if (findPath(start1, exit1, maze)) {
        cout << "Path found." << endl;
    } else {
        cout << "No path found." << endl;
    }

    // 清除访问记录以进行下一次测试
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (maze[i][j] != 9) {
                maze[i][j] = 0;
            }
        }
    }

    // 测试样例2
    Point start2 = {1, 1};
    Point exit2 = {8, 8};
    cout << "Path from (1,1) to (8,8): ";
    if (findPath(start2, exit2, maze)) {
        cout << "Path found." << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
