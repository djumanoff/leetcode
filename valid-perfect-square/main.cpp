#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }
        int l = 0;
        int r = num;

        while (l<r) {
            int m = (l+r)/2;
            int m2 = m * m;
            cout << m << endl;
            if (m2 == num) {
                return true;
            }
            if (l == m) {
                return false;
            }
            if (m2 > num) {
                r = m;
            } else {
                l = m;
            }
        }
        return false;
    }
};

int main() {
    Solution s;

    cout << s.isPerfectSquare(16);

    return 0;
}
