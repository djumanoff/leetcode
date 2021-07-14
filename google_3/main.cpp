#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

// O(n * (slen + dlen))
string longestWord(string s, vector<string> dict) {
    string result = "";
    int cnt = 0;
    for (int i = 0; i < dict.size(); i++) {
        int si = 0;
        int di = 0;
        while (si < s.size() && di < dict[i].size()) {
            // cnt++;
            if (s[si] == dict[i][di]) {
                si++;
                di++;
                if (di == dict[i].size() && dict[i].size() > result.size()) {
                    result = dict[i];
                }
            } else {
                si++;
            }
        }
    }
    // cout << cnt << endl;
    return result;
}

int main() {
    vector<string> v1 {"able", "ale", "apple", "bale", "kangaroo"};
    cout << longestWord("abppplee", v1) << endl;
    return 0;
}
