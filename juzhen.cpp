#include <iostream>
#include <vector>

using namespace std;
struct Triple{
    int row; 
    int col; 
    int value;  
    Triple(int r = 0, int c = 0, int v = 0):row(r),col(c),value(v){}
};

class SparseMatrix{
private:
    vector<Triple> triples; 
    int rows;  
    int cols;            
    int nums;             

public:
    SparseMatrix(int r, int c, int num, const vector<Triple>& t):rows(r),cols(c),nums(num),triples(t){}
    void init(const vector<Triple>& t){
        triples = t;
    }
    SparseMatrix bfTranspose() {
        vector<Triple> transposedTriples(nums); 
        int count = 0;

        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < nums; ++j) {
                if (triples[j].col == i) {
                    transposedTriples[count++] = Triple(triples[j].col, triples[j].row, triples[j].value);
                }
            }
        }

        return SparseMatrix(cols, rows, nums, transposedTriples);
    }
    SparseMatrix fastTranspose() {
        vector<int> rowTerms(cols, 0); 
        vector<int> startingPos(cols); 
        for (int i = 0; i < nums; ++i) {
            rowTerms[triples[i].col]++;
        }
        startingPos[0] = 0;
        for (int i = 1; i < cols; ++i) {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }

        vector<Triple> transposedTriples(nums);
        for (int i = 0; i < nums; ++i) {
            int j = startingPos[triples[i].col]++;
            transposedTriples[j] = Triple(triples[i].col, triples[i].row, triples[i].value);
        }

        return SparseMatrix(cols, rows, nums, transposedTriples);
    }
    void printMatrix() {
        int count = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (count < nums && triples[count].row == i && triples[count].col == j) {
                    cout << triples[count++].value << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    vector<Triple> testTriples;
    testTriples.push_back(Triple(1, 2, 12));
    testTriples.push_back(Triple(1, 3, 9));
    testTriples.push_back(Triple(3, 1, -3));
    testTriples.push_back(Triple(3, 6, 14));
    testTriples.push_back(Triple(4, 3, 24));
    testTriples.push_back(Triple(5, 2, 18));
    testTriples.push_back(Triple(6, 1, 15));
    testTriples.push_back(Triple(6, 4, -7));

    SparseMatrix sm(6, 7, 8, testTriples);

    cout << "Original Matrix:" << endl;
    sm.printMatrix();

    SparseMatrix bfTransposed = sm.bfTranspose();
    cout << "Fast Transposed Matrix:" << endl;
    bfTransposed.printMatrix();

    return 0;
}
