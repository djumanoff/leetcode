#include <vector>
#include <iostream>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_2darr(vector<vector<int> > v) {
    for (int i = 0; i < v.size(); i++) {
        print_arr(v[i]);
    }
    cout << endl;
};

class Solution {
public:
    vector<vector<int> > generate(int numRows) {        
        if (numRows == 0) {
            vector<vector<int> > result;
            return result;
        }
        vector<vector<int> > result(numRows);
        result[0] = vector<int>(1);
        result[0][0] = 1;
        if (numRows == 1) {
            return result;
        }
        
        result[1] = vector<int>(2);
        result[1][0] = 1;
        result[1][1] = 1;
        if (numRows == 2) {
            return result;
        }
        
        for (int i = 3; i <= numRows; ++i) {
            result[i-1] = vector<int>(i);
            result[i-1][0] = 1;
            result[i-1][i-1] = 1;
            for (int j = 1; j < i; ++j) {
                result[i-1][j] = result[i-2][j] + result[i-2][j-1];
            }
        }
        
        return result;
    }
};

int main() {
    Solution s;

    print_2darr(s.generate(5));
    return 0;
}
