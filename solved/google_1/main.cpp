#include <iostream>
#include <vector>
#include <string>

using namespace std;

string repeat(string s, int cnt) {
    string result = "";
    for (int i = 0; i < cnt; i++) {
        result += s;
    }
    return result;
}

string decompress(string s, int times) {
    // cout << "s = " << s << " times = " << times << endl;
    string curr = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            curr += s[i];
        } else if (s[i] >= '0' && s[i] <= '9') {
            string numStr = "";
            while (s[i] != '[') {
                numStr += s[i];
                i++;
            }
            int numOfRepeats = stoi(numStr);
            return repeat(curr + decompress(s.substr(i+1, s.length()), numOfRepeats), times);
        } else if (s[i] == ']') {
            return repeat(curr, times) + decompress(s.substr(i+1, s.length()), 1);
        }
    }
    return curr;
}

string decompress(string s) {
    return decompress(s, 1);
}

int main() {
    // 3[abc]4[ab]c
    cout << decompress("3[abc]4[ab]c") << endl;

    // 2[3[a]b]
    cout << decompress("2[3[a]b]") << endl;
    return 0;
}
