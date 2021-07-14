#include <vector>
#include <iostream>

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
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > dp(m+2);
        for (int i = 0; i < m + 2; i++) {
            dp[i] = vector<int>(n+2);
            for (int j = 0; j < n + 2; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        dp[1][1] = grid[0][0];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) continue ;
                // check check from where we come here
                // int minVal = min(min(dp[i-1][j], dp[i][j-1]), min(dp[i+1][j], dp[i][j+1]));
                int minVal = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = minVal + grid[i-1][j-1];
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution s;
    vector<vector<int> > v {{1,3,1}, {1,5,1}, {4,2,1}};
    cout << s.minPathSum(v);
    return 0;
}
