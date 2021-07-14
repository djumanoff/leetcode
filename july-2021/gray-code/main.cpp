#include <vector>
#include <iostream>
#include <unordered_map> 

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

class Solution {
public:
    int maxN;
    int upperCnt; 

    unordered_map<int, bool> set;

    vector<int> grayCode(int n) {
        maxN = n;

        int upper = pow(2, n);
        upperCnt = upper;

        vector<int> ans(upper);

        ans[0] = 0;
        set[0] = true;

        backtrack(ans, 1);

        return ans;
    }

    void backtrack(vector<int>& ans, int idx) {
        for (int i = 1; i < upperCnt; i <<= 1) {
            int next = ans[idx-1] ^ i;
            if (set[next]) continue ;
            ans[idx] = next;
            set[next] = true;
            if (idx == upperCnt - 1) {
                return;
            }
            backtrack(ans, idx + 1);
        }
    }

    int pow(int n, int p) {
        int ans = 1;
        for (int i = 0; i < p; ++i) {
            ans *= n;
        }
        return ans;
    }
};

int main() {
    Solution s;

    print_arr(s.grayCode(3));

    // cout << s.pow(2, 3) << endl;

    return 0;
}
