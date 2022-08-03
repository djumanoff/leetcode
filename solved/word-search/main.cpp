#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int xdir[4] = {0, 1, 0, -1};
    int ydir[4] = {1, 0, -1, 0};

    vector<vector<char>> b;
    vector<vector<bool>> v;
    string w;

    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        w = word;
        initEmptyVisited();

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (findWord(i, j, 0)) {
                    return true;
                }
                initEmptyVisited();
            }
        }
        return false;
    }

    void initEmptyVisited() {
        v = vector<vector<bool>>(b.size());
        for (int i = 0; i < b.size(); ++i) {
            v[i] = vector<bool>(b[i].size(), false);
        }
    }

    bool findWord(int x, int y, int wi) {
        if (b[x][y] != w[wi]) return false;
        if (wi == w.size() - 1) return true;

        v[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int newx = x + xdir[i];
            int newy = y + ydir[i];
            if (!isValid(newx, newy) || v[newx][newy]) continue;
            if (findWord(newx, newy, wi + 1)) return true;
            v[newx][newy] = false;
        }
        return false;
    }

    bool isValid(int x, int y) {
        if (x >= b.size() || x < 0) return false;
        if (y >= b[0].size() || y < 0) return false;
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> v {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'E', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    cout << s.exist(v, "ABCEFSADEESE") << endl; // "ABCCED"

    return 0;
}
