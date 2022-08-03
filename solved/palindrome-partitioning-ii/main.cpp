#include <string>
#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<bool> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_2darr(vector<vector<bool> > v) {
    for (int i = 0; i < v.size(); i++) {
        print_arr(v[i]);
    }
};

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = vector<bool>(n);
            dp[i][i] = true;
        }
        
        for (int i = 0; i < n-1; ++i) {
            dp[i][i+1] = s[i] == s[i+1];
        }
        
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i <= n-l; ++i) {
                int j = i + l - 1;
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
            }
        }

        vector<int> mincut(n, INT_MAX);
        mincut[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (dp[0][i]) {
                mincut[i] = 0;
            } else {
                for (int j = 0; j < i; ++j) {
                    if (dp[j+1][i] && (mincut[j] + 1 < mincut[i])) {
                        mincut[i] = mincut[j] + 1;
                    }
                }
            }
        }

        return mincut[n-1];
    }
};


int main() {
    Solution s;

    cout << s.minCut("aacbcaa");

    return 0;
}
