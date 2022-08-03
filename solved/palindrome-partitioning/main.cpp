#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print_arr(vector<string> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_2darr(vector<vector<string> > v) {
    for (int i = 0; i < v.size(); i++) {
        print_arr(v[i]);
    }
};

class Solution {
public:
    vector<vector<string>> ans;
    
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(s, 0, v);

        return ans;
    }
    
    void solve(const string& s, int idx, vector<string>& v) {
        if (idx == s.size()) {
            ans.push_back(v);
            return ;
        }
        string s1 = "";
        for (int i = idx; i < s.size(); ++i) {
            s1 += s[i];
            if (isPalyndrome(s1)) {
                v.push_back(s1);
                solve(s, i + 1, v);
                v.pop_back();
            }
        }
    }
    
    bool isPalyndrome(string s) {
        int n = s.size();
        if (n == 1) return true;

        int l = 0;
        int r = n - 1;

        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};

int main() {
    Solution s;

    print_2darr(s.partition("aab"));

    return 0;
}
