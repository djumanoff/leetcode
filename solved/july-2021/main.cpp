#include <vector> 
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void print_arr(vector<char> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_2darr(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        print_arr(v[i]);
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int curr = 0;
        int n = matrix.size();
        vector<int> dp(n);
        int min = INT_MAX;
        int minIdx = 0;
        
        for (; k > 0; --k) {
            min = INT_MAX;
            minIdx = 0;
            for (int i = 0; i< n; ++i) {
                if (dp[i] >= n) continue;
                if (matrix[i][dp[i]] < min) {
                    min = matrix[i][dp[i]];
                    minIdx = i;
                }
            }
            dp[minIdx]++;
        }
        // print_arr(dp);
        // cout << minIdx << endl;

        return matrix[minIdx][(dp[minIdx]-1)];
    }

    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> maxarr(n);
        maxarr[n-1] = arr[n-1];
        for (int i = n - 2; i >= 0; --i) {
            maxarr[i] = max(maxarr[i+1], arr[i+1]);
        }
        maxarr[n-1] = -1;
        return maxarr;
    }
    
    int countVowelPermutation(int n) {
        unordered_map<char, vector<unsigned long long>> dp;

        char ch[5] = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < 5; ++i) {
            dp[ch[i]] = vector<unsigned long long>(n+1);
            dp[ch[i]][0] = 0;
            dp[ch[i]][1] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            dp['a'][i] = dp['i'][i-1] + dp['u'][i-1] + dp['e'][i-1];
            dp['e'][i] = dp['a'][i-1] + dp['i'][i-1];
            dp['i'][i] = dp['e'][i-1] + dp['o'][i-1];
            dp['o'][i] = dp['i'][i-1];
            dp['u'][i] = dp['o'][i-1] + dp['i'][i-1];
        }

        unsigned long long sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += dp[ch[i]][n];
        }
        if (sum > 1000000007) {
            sum %= 1000000007;
        }

        return (int)sum;
    }

    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            int mod = (columnNumber-1) % 26;
            ans = (char)('A' + mod) + ans;
            columnNumber = (columnNumber-1) / 26;
        }
        return ans;
    }

    int titleToNumber(string columnTitle) {
        int ans = 0;
        int mul = 1;
        for (int i = columnTitle.size() - 1; i >= 0; --i) {
            int idx = columnTitle[i] - 'A';
            ans += (idx+1) * mul;
            mul *= 26;
        }
        return ans;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1);
        for (int i = 0; i < m+1; ++i) {
            dp[i] = vector<int>(n+1, 0);
        }
        int ans = 0;
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                    if (dp[i][j] > ans) ans = dp[i][j];
                }
            }
        }
        return ans;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] + nums[i];
        }

        print_arr(dp);
        return 0;
    }

    vector<int> getRow(int r) {
        vector<int> ans(r+1, 0);
        ans[0] = 1;
        if (r == 0) {
            return ans;
        }
        for (int i = 1; i <= r; ++i) {
            for (int j = i; j > 0; --j) {
                ans[j] += ans[j-1];
            }
        }
        return ans;
    }

};

int main() {
    Solution s;
    // vector<vector<int>> v { {1,5,9},{10,11,13},{12,13,15} };
    // cout << s.kthSmallest(v, 8);

    // vector<int> v1 {17,18,5,4,6,1};
    // print_arr(s.replaceElements(v1));

    // cout << s.countVowelPermutation(144) << endl;
    //   18208803
    //  520762870
    // 1000000007

    // string s1 = "abc";

    // cout << s1.substr(0, 1) << endl;
    // cout << s1.substr(1) << endl;

    // cout << s1 << endl;

    // cout << s.convertToTitle(701) << endl;
    // vector<int> v1 {1,2,3,2,1};
    // vector<int> v2 {3,2,1,4,7};

    // cout << s.findLength(v1, v2) << endl;

    // vector<int> v1 {0, 0, 0, 0, 0};
    // vector<int> v2 {0, 0, 0, 0, 0};

    // cout << s.findLength(v1, v2) << endl;

    // vector<int> v {2,3,1,2,4,3};
    // cout << s.getPermutation(3, 3) << endl;

    print_arr(s.getRow(3));

    return 0;
}
