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
    vector<vector<string> > result;
    int boardSize;

    vector<vector<string> > solveNQueens(int n) {
        if (n > 1 && n < 4) {
            return result;
        }
        if (n == 1) {
            vector<string> v;
            v.push_back("Q");
            result.push_back(v);
            return result;
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
            vector<string> ans = getAnswer();
            result.push_back(ans);
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

    vector<string> getAnswer() {
        vector<string> result;
        for (int row = 0; row < boardSize; row++) {
            string rowString;
            for (int col = 0; col < boardSize; col++) {
                rowString += '.';                
            }
            result.push_back(rowString);
        }

        for (int i = 0; i < boardSize; i++) {
            result[occupiedRows[i]][occupiedCols[i]] = 'Q';
        }
        return result;
    }
};

int main() {
    Solution s;

    s.solveNQueens(5);

    return 0;
}
