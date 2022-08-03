#include <vector>
#include <iostream>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unsigned char num;
        
        vector<int> v(cells.size());
        
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < 7; ++j) {
                v[j] = (cells[j-1] == cells[j+1]) ? 1 : 0;
            }
            for (int j = 0; j < 8; ++j) {
                cells[j] = v[j];
            }
        }
        cells[0] = 0;
        cells[7] = 0;
        return cells;
    }
};



int main() {
    Solution s;

    vector<int> v {0,1,0,1,1,0,0,1};
    print_arr(s.prisonAfterNDays(v, 7));

    return 0;
}
