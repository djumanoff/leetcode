#include <string>
#include <vector>
#include <iostream>

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
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> palindrome(n);
        for (int i = 0; i < n; ++i) {
            palindrome[i] = vector<bool>(n);
            palindrome[i][i] = true;
        }
        
        for (int i = 0; i < n-1; ++i) {
            palindrome[i][i+1] = s[i] == s[i+1];
        }
        
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i <= n-l; ++i) {
                int j = i + l - 1;
                palindrome[i][j] = palindrome[i+1][j-1] && (s[i] == s[j]);
            }
        }

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                bool t = palindrome[0][i] && palindrome[i+1][j] && palindrome[j+1][n-1];
                if (t) return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    cout << s.checkPartitioning("bbab") << endl;

    return 0;
}
