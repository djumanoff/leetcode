#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void print_map(unordered_map<int, bool> strMem) {
    for (auto it = strMem.begin(); it != strMem.end(); it++) {
        cout << it->first << " = " << it->second << endl;
    }
}

class Solution {
public:
    unordered_map<string, bool> dictMem;
    unordered_map<int, bool> strMem;

    bool wordBreak(string s, vector<string>& wordDict) {
        dictMem.clear();
        strMem.clear();

        for (string ss : wordDict) {
            dictMem[ss] = true;
        }
        
        bool result = solve(s);
        return result;
    }

    bool solve(string s) {
        cout << s << endl;
        if (s == "") {
            return true;
        }
        if (strMem.find(s.length()) != strMem.end()) {
            return strMem[s.length()];
        }
        string curr = "";
        for (int i = 0; i < s.length(); i++) {
            curr += s[i];
            if (dictMem[curr]) {
                if (solve(s.substr(i+1, s.length()))) {
                    return strMem[s.length()] = true;
                }
            }
        }
        return strMem[s.length()] = false;
    }
};


int main() {
    Solution s;
    // vector<string> wordDict {"apple", "pen", "pencil"};
    // cout << s.wordBreak("applepenapplepencil", wordDict) << endl;

    // vector<string> wordDict1 {"cats","dog","sand","and","cat"};
    // cout << s.wordBreak("catsandog", wordDict1) << endl;

    // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
    // ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

    vector<string> wordDict2 {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict2) << endl;
    return 0;
}
