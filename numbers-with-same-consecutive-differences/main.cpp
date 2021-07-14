#include <iostream>
#include <vector>

using namespace std; 

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

class Solution {
public:
    vector<int> result;

    vector<int> numsSameConsecDiff(int n, int k) {
        result.clear();

        findAll(1, 1, k, n);

        return result;
    }

    void findAll(int curr, int digitCnt, int k, int n) {
        // calculate next digit
        int mod = curr % 10;
        int nextDigit1 = mod + k;
        if (nextDigit1 < 10) {
            int newNum = curr * 10 + nextDigit1;
            int newDigCnt = digitCnt + 1;
            if (newDigCnt == n) {
                result.push_back(newNum);
            } else {
                findAll(newNum, newDigCnt, k, n);
            }
        }
        int nextDigit2 = mod - k;
        if (nextDigit2 >= 0 && nextDigit1 != nextDigit2) {
            int newNum = curr * 10 + nextDigit2;
            int newDigCnt = digitCnt + 1;
            if (newDigCnt == n) {
                result.push_back(newNum);
            } else {
                findAll(newNum, newDigCnt, k, n);
            }
        }

        // no valid digit 
        if (mod < 9 && digitCnt == 1) {
            findAll(curr + 1, digitCnt, k, n);
        }
    }
};

int main() {
    Solution s;

    print_arr(s.numsSameConsecDiff(3, 7));

    print_arr(s.numsSameConsecDiff(2, 1));

    print_arr(s.numsSameConsecDiff(2, 0));

    return 0;
}
