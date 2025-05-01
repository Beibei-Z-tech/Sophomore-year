#include <iostream>
#include <vector>
#include <stack>
#include <chrono>
#include <thread>

using namespace std;

struct Point {
    int x, y;
};

bool isValid(int x, int y, const vector<vector<int> > &maze, vector<vector<bool> > &visited) {
    return (x >= 0) && (x < maze.size()) && (y >= 0) && (y < maze[0].size()) 
           && maze[x][y] == 0 && !visited[x][y];
}

void printMaze(const vector<vector<int> > &maze, const vector<vector<bool> > &visited) {
    for (int i = 0; i < maze.size(); ++i) {
        for (int j = 0; j < maze[0].size(); ++j) {
            if (visited[i][j]) {
                cout << "·"; // Mark visited cells with a dot
            } else if (maze[i][j] == 9) {
                cout << "█"; // Walls
            } else {
                cout << " "; // Paths
            }
        }
        cout << endl;
    }
}

bool findPath(Point start, Point exit, vector<vector<int> > &maze, vector<vector<bool> > &visited) {
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
                
                // Print the maze with the current path
                printMaze(maze, visited);
                this_thread::sleep_for(chrono::milliseconds(200)); // Delay for animation
            }
        }
    }
    return false;
}

int main() {
    const int rows = 10;
    const int cols = 10;
    vector<vector<int> > maze(rows, vector<int>(cols));
    vector<vector<bool> > visited(rows, vector<bool>(cols, false));
    
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
    cout << "Finding path from (1,1) to (8,8): " << endl;
    if (findPath(start1, exit1, maze, visited)) {
        cout << "Path found." << endl;
    } else {
        cout << "No path found." << endl;
    }

    // 清除访问记录以进行下一次测试
    for (int i = 0; i<rows; ++i) {
        for (int j = 0; j<cols; ++j) {
            if (maze[i][j] != 9){
                maze[i][j] = 0; 
            }
        }
    }
    // 测试样例2
    Point start2 = {1, 1};
    Point exit2 = {8, 8};
    cout << "Finding path from (1,1) to (8,8): " << endl;
    if (findPath(start2, exit2, maze, visited)) {
        cout << "Path found." << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}



