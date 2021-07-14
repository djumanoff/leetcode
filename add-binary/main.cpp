#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string answer = "";
        bool addone = false;
        
        while (i >=0 && j >= 0) {
            if (a[i] == a[j] && a[i] == '0') {
                if (!addone) {
                    answer = '0' + answer;
                } else {
                    answer = '1' + answer;
                    addone = false;
                }
            } else if (a[i] == a[j] && a[i] == '1') {
                if (!addone) {
                    answer = '0' + answer;
                } else {
                    answer = '1' + answer;
                }
                addone = true;
            } else {
                answer = '1' + answer;
            }
            i--;
            j--;
        }
        
        while (i >= 0) {
            if (a[i] == '0') {
                if (!addone) {
                    answer = '0' + answer;
                } else {
                    answer = '1' + answer;
                    addone = false;
                }
            } else {
                if (!addone) {
                    answer = '1' + answer;
                } else {
                    answer = '0' + answer;
                    addone = true;
                }
            }
            i--;
        }
        
        while (j >= 0) {
            if (a[j] == '0') {
                if (!addone) {
                    answer = '0' + answer;
                } else {
                    answer = '1' + answer;
                    addone = false;
                }
            } else {
                if (!addone) {
                    answer = '1' + answer;
                } else {
                    answer = '0' + answer;
                    addone = true;
                }
            }
            j--;
        }
            
        if (addone) {
            answer = '1' + answer;
        }
        
        return answer;
    }
};

int main() {
    Solution s;

    cout << s.addBinary("11", "1") << endl;

    return 0;
}
