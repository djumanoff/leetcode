#include <iostream>

using namespace std; 

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x <= 2) {
            return 1;
        }

        int l = 0;
        int r = x;

        while (l<r) {
            long m = (l+r) / 2;
            long m2 = m * m;
            if (m2 == x || m == l) {
                return m;
            } else if (m2 > x) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    }
};


int main() {

    Solution s;
    cout << s.mySqrt(2147395599) << endl;

    return 0;
}
