#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_arr(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    cout << endl;
};

class Solution {
    
public:
    vector<int> occupiedRows;
    vector<int> occupiedCols;
    int result;
    int boardSize;

    int totalNQueens(int n) {
        result = 0;
        if (n > 1 && n < 4) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        // 2d array to store coordinates of all queens on the board
        occupiedRows = vector<int>(n);
        occupiedCols = vector<int>(n);
        boardSize = n;

        // empty board
        removeQueens();

        // start placing queens
        canPlaceOnRow(0);

        return result;
    }

    void removeQueens() {
        for (int j = 0; j < boardSize; j++) {
            occupiedRows[j] = -1;
            occupiedCols[j] = -1;
        }
    }

    void canPlaceOnRow(int row) {
        if (row == boardSize) {
            result++;
        }
        bool canPlace = true;
        for (int col = 0; col < boardSize; col++) {
            canPlace = true;
            for (int q = 0; q < row; q++) {
                if (occupiedCols[q] == col 
                || occupiedRows[q] - occupiedCols[q] == row - col 
                || occupiedRows[q] + occupiedCols[q] == row + col) {
                    canPlace = false;
                    break; 
                }
            }
            if (canPlace) {
                occupiedRows[row] = row;
                occupiedCols[row] = col;
                canPlaceOnRow(row + 1);
            }
        }
    }
};

int main() {
    Solution s;

    cout << s.totalNQueens(5);

    return 0;
}
