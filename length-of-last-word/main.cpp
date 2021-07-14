#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int i = s.size()-1;
        for (; i >= 0; i--) {
            if (s[i] != ' ') {
                i--;
                cnt++;
                break;
            }
        }
        for (; i >= 0; i--) {
            if (s[i] == ' ') {
                break;
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};


int main() {
    Solution s;
    cout << s.lengthOfLastWord("Hello World ") << endl;
}

