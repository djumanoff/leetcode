#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<int, int> positions;

public:
    int minSwapsCouples(vector<int>& row) {
        for (int i = 0; i < row.size(); i++) {
            positions[row[i]] = i;
        }
        int swapCount = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int current = row[i];
            int expectedNext = current ^ 1;
            if (expectedNext != row[i+1]) {
                swap(row, i+1, positions[expectedNext]);
                swapCount++;
            }
        }
        return swapCount;
    }

    void swap(vector<int>& row, int i, int j) {
        int t = row[i];
        row[i] = row[j];
        row[j] = t;

        positions[row[i]] = i;
        positions[row[j]] = j;
    }
};


int main() {
    Solution s;
    vector<int> v1 {0, 2, 1, 3};
    cout << s.minSwapsCouples(v1) << endl;

    vector<int> v2 {3, 2, 0, 1};
    cout << s.minSwapsCouples(v2) << endl;

    return 0;
}
