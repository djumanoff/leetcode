#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result; 
        int m = matrix.size();
        int n = matrix[0].size();
        int l = numOfIter(m, n);
        for (int i = 0; i < l; i++) {
            int c = i;
            int r = i;
            // right
            if (c < n - i) {
                for (; c < n - i; ++c) {
                    result.push_back(matrix[r][c]);
                }
                c--;
            } else {
                break;
            }
            
            // down
            r++;
            if (r < m - i) {
                for (; r < m - i; ++r) {
                    result.push_back(matrix[r][c]);
                }
                r--;
            } else {
                break;
            }
            
            // left
            c--;
            if (c >= i) {
                for (; c >= i; --c) {
                    result.push_back(matrix[r][c]);
                }
                c++;
            } else {
                break;
            }

            // up 
            r--;
            if (r >= i + 1) {                
                for (; r >= i + 1; --r) {
                    result.push_back(matrix[r][c]);
                }
            } else {
                break;
            }
        }
        return result;
    }

private:
    int numOfIter(int m, int n) {
        int r = min(m, n);
        return r / 2 + r % 2;
    }
};

int main() {
    Solution s;
    vector<vector<int> > matrix;

    vector<int> v1;
    v1.push_back(1);
    // v1.push_back(2);
    // v1.push_back(3);
    // v1.push_back(4);

    vector<int> v2;
    v2.push_back(5);
    // v2.push_back(6);
    // v2.push_back(7);
    // v2.push_back(8);

    vector<int> v3;
    v3.push_back(9);
    // v3.push_back(10);
    // v3.push_back(11);
    // v3.push_back(12);

    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);

    vector<int> result = s.spiralOrder(matrix);
    print_vec(result);

    return 0;
}
