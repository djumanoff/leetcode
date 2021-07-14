#include <vector>
#include <iostream>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i + 1; j <= (i + nums[i]); ++j) {
                if (dp[j] == 0) {
                    dp[j] = dp[i] + 1;
                } else {
                    dp[j] = min(dp[i] + 1, dp[j]);
                }
                if (j == n - 1) return dp[j];
            }
        }
        
        return dp[n-1];
    }
};

int main() {
    Solution s;

    vector<int> v {2,3,1,1,4};
    cout << s.jump(v) << endl;

    return 0;
}
