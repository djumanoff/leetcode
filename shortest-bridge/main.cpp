#include <vector> 
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_2darr(vector<vector<int> > v) {
    for (int i = 0; i < v.size(); i++) {
        print_arr(v[i]);
    }
    cout << endl;
};

class Solution {
    int xdir[4] = {0, 1, 0, -1};
    int ydir[4] = {1, 0, -1, 0};

public:
    bool isInGrid(int x, int y, int size) {
        return (x >= 0 && x < size && y >= 0 && y < size);
    }

    void dfs(vector<vector<int> >& grid, int x, int y) {
        if (!isInGrid(x, y, grid.size()) || grid[x][y] != 1) {
            return ;
        }
        grid[x][y] = 2;
        for (int i = 0; i < 4; i++) {
            int newX = xdir[i] + x;
            int newY = ydir[i] + y;
            dfs(grid, newX, newY);
        }
    }

    int shortestBridge(vector<vector<int> >& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        // find first island
        findfirstIsland(grid);

        queue<pair<int, int> > q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int result = 0;
        while (!q.empty()) {
            int qsize = q.size();
            // making waves
            for (int j = 0; j < qsize; j++) {
                auto el = q.front();
                q.pop();
                if (grid[el.first][el.second] == 1) {
                    // subtrack 1, don't count last wave
                    return result - 1;
                }
                for (int i = 0; i < 4; i++) {
                    int newX = xdir[i] + el.first;
                    int newY = ydir[i] + el.second;
                    if (!isInGrid(newX, newY, grid.size()) || grid[newX][newY] == 2) {
                        continue;
                    }
                    if (grid[newX][newY] == 0) {
                        grid[newX][newY] = 2;                        
                    }
                    q.push({newX, newY});
                }
            }
            // count each wave
            result++;
        }

        return result;
    }

    void findfirstIsland(vector<vector<int> >& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return ;
                }
            }
        }
    }
};

int main() {
    Solution s;

    vector<vector<int> > v1 {{0, 1}, {1, 0}};
    cout << s.shortestBridge(v1) << endl;

    vector<vector<int> > v2 {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
    cout << s.shortestBridge(v2) << endl;

    return 0;
}
