#include <iostream>
#include <vector>

using namespace std;
bool isSymmetric(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

vector<int> compressSymmetric(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> compressed((n * (n + 1)) / 2);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            compressed[index++] = matrix[i][j];
        }
    }
    return compressed;
}

vector<vector<int>> decompressSymmetric(const vector<int>& compressed) {
    int n = static_cast<int>(-0.5 + sqrt(0.25 + 2 * compressed.size()));
    vector<vector<int>> matrix(n, vector<int>(n));
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            matrix[i][j] = compressed[index++];
            matrix[j][i] = matrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> matrix1 = {
        {1, 2},
        {2, 3}
    };

    vector<vector<int>> matrix2 = {
        {1, 4, 6, 5},
        {4, 3, 7, 9},
        {6, 7, 0, 2},
        {5, 9, 2, 8}
    };

    if (isSymmetric(matrix1)) {
        vector<int> compressed1 = compressSymmetric(matrix1);
        cout << "Compressed symmetric matrix 1:" << endl;
        for (int val : compressed1) {
            cout << val << " ";
        }
        cout << endl;

        vector<vector<int>> decompressed1 = decompressSymmetric(compressed1);
        cout << "Decompressed matrix 1:" << endl;
        printMatrix(decompressed1);
    }

    if (isSymmetric(matrix2)) {
        vector<int> compressed2 = compressSymmetric(matrix2);
        cout << "Compressed symmetric matrix 2:" << endl;
        for (int val : compressed2) {
            cout << val << " ";
        }
        cout << endl;
        vector<vector<int>> decompressed2 = decompressSymmetric(compressed2);
        cout << "Decompressed matrix 2:" << endl;
        printMatrix(decompressed2);
    }

    return 0;
}
