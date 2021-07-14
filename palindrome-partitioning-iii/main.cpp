#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_2arr(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        print_arr(v[i]);
    }
};

void print_3arr(vector<vector<vector<int>>> v) {
    for (int i = 0; i < v.size(); i++) {
        print_2arr(v[i]);
        cout << endl;
    }
};

class Solution {
public:
    vector<vector<int>> palindrome;
    vector<vector<vector<int>>> dp;

    int palindromePartition(string s, int k) {
        int n = s.size();
        dp = vector<vector<vector<int>>>(n);
        palindrome = vector<vector<int>>(n);
        vector<int> v(k+1, -1);
        for (int i = 0; i < n; ++i) {
            palindrome[i] = vector<int>(n);
            palindrome[i][i] = 0;
            dp[i] = vector<vector<int>>(n, v);
        }
        
        for (int i = 0; i < n-1; ++i) {
            palindrome[i][i+1] = s[i] == s[i+1] ? 0 : 1;
        }
        
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i <= n-l; ++i) {
                int j = i + l - 1;
                palindrome[i][j] = palindrome[i+1][j-1] + (s[i] == s[j] ? 0 : 1);
            }
        }
        int ans = solve(s, 0, n-1, k);        
        return ans;
    }

    int solve(string s, int l, int r, int k) {
        if (r - l + 1 < k) {
            dp[l][r][k] = 101;
            return 101;
        }
        if (r - l + 1 == k) {
            dp[l][r][k] = 0;
            return 0;
        }
        if (k == 0) {
            dp[l][r][k] = 101;
            return 101;
        }
        if (k == 1) {
            int cnt = palindrome[l][r];
            dp[l][r][k] = cnt;
            return cnt;
        }
        if (dp[l][r][k] != -1) {
            return dp[l][r][k];
        }
        int mincnt = 101;
        for (int i = l; i < r; ++i) {
            int cnt = palindrome[l][i] + solve(s, i+1, r, k-1);
            if (cnt < mincnt) {
                mincnt = cnt;
            }
        }
        dp[l][r][k] = mincnt;

        return mincnt;
    }
};

int main() {
    Solution s;

    cout << s.palindromePartition("abc", 1) << endl;

    return 0;
}

// bcdcbc
// bcaff
