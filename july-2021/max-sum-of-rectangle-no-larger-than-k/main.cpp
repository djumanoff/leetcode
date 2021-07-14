#include <vector>
#include <iostream>

using namespace std;

void print_arr(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
};

void print_2darr(vector<vector<int> > nums) {
    for (int i = 0; i < nums.size(); i++) {
        print_arr(nums[i]);
    }
    cout << endl;
};

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m);        
        for (int i = 0; i < m; ++i) {
            dp[i] = vector<int>(n, 0);
        }

        dp[0][0] = matrix[0][0];
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i-1] + matrix[0][i];
        }
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + matrix[i][0];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
            }
        }

        int max = INT_MIN;
        if (m == 1) {
            for (int j = 0; j < n; ++j) {
                int curr = dp[0][j];
                max = (curr > max && curr <= k) ? curr : max;
                for (int o = 0; o < j; ++o) {
                    int curr = dp[0][j] - dp[0][o];
                    max = (curr > max && curr <= k) ? curr : max;
                }
            }
            return max;
        } else if (n == 1) {
            for (int i = 0; i < m; ++i) {
                int curr = dp[i][0];
                max = (curr > max && curr <= k) ? curr : max;
                for (int l = 0; l < i; ++l) {
                    int curr = dp[i][0] - dp[l][0];
                    max = (curr > max && curr <= k) ? curr : max;
                }
            }
            return max;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int curr = dp[i][j];
                max = (curr > max && curr <= k) ? curr : max;

                for (int l = 0; l < i; ++l) {
                    curr = dp[i][j] - dp[l][j];
                    max = (curr > max && curr <= k) ? curr : max;

                    for (int o = 0; o < j; ++o) {
                        int curr = dp[i][j] - dp[i][o] - dp[l][j] + dp[l][o];
                        max = (curr > max && curr <= k) ? curr : max;
                        curr = dp[i][j] - dp[i][o];
                        max = (curr > max && curr <= k) ? curr : max;                            
                    }
                }
            }
        }

        return max;
    }
};

int main() {
    Solution s;

    vector<vector<int>> v { {1, 0, 1}, {0, -2, 3} };
    cout << s.maxSumSubmatrix(v, 2) << endl;

    vector<vector<int>> v1 { {2, 2, -1} };
    cout << s.maxSumSubmatrix(v1, 3) << endl;

    vector<vector<int>> v2 { {2, 2, -1} };
    cout << s.maxSumSubmatrix(v2, 0) << endl;

    return 0;
}
