#include <iostream>
#include <vector> 
#include <map>

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
    int numberOfGoodStrings(int n) {
        if (n == 0) {
            return 1;
        }

        vector<vector<int> > dp(10);
        for (int i = 1; i < 10; i++) {
            dp[i] = vector<int>(n+1);
        }

        for (int i = 1; i < 10; i++) {
            dp[i][1] = 1;
        }

        for (int i = 2; i <= n; i++) {
            int sum = 0;
            for (int j = 1; j < 10; j++) {
                sum += dp[j][i-1];
            }
            for (int j = 1; j < 10; j++) {
                if (i - j > 1) {
                    dp[j][i] = sum - dp[j][i-1];
                } else if (i - j == 1) {
                    dp[j][i] = sum - 1;
                } else {
                    dp[j][i] = sum;
                }
            }
        }

        // print_2darr(dp);

        int answer = 0;
        for (int i = 1; i < 10; ++i) {
            answer += dp[i][n];
        }

        return answer;
    }
};

int main() {
    Solution s;

    cout << s.numberOfGoodStrings(5) << endl;

    return 0;
}
