#include <string>
#include <iostream>
#include <vector>

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
    int minDistance(string word1, string word2) {
        int n = word2.size();
        int m = word1.size();

        vector<vector<int> > dp(n+1);

        for (int i = 0; i <= n; ++i) {
            dp[i] = vector<int>(m+1);
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
                if (i == 0) {
                    dp[i][j] = j;
                }
                if (j == 0) {
                    dp[i][j] = i;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[j-1] == word2[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
        }

        return dp[n][m];
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }
};

int main() {
    Solution s;

    cout << s.minDistance("horse", "ros") << endl;

    cout << s.minDistance("a", "ab") << endl;

    // "zoologicoarchaeologist"
    // "zoogeologist"
    cout << s.minDistance("zoologicoarchaeologist", "zoogeologist") << endl;

    return 0;
}
