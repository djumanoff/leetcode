#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> leftMax;
    vector<int> rightMax;

    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }
        initMaxArrays(height);

        int trapedWater = 0;
        for (int i = 0; i < n; ++i) {
            trapedWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return trapedWater;
    }

    void initMaxArrays(vector<int>& height) {
        int n = height.size();
        leftMax = vector<int>(n);
        leftMax[0] = height[0];

        for (int i = 1; i < height.size(); ++i) {
            if (leftMax[i-1] > height[i]) {
                leftMax[i] = leftMax[i-1];
            } else {
                leftMax[i] = height[i];
            }
        }

        rightMax = vector<int>(n);
        rightMax[n-1] = height[n-1];

        for (int i = n-2; i >= 0; --i) {
            if (rightMax[i+1] > height[i]) {
                rightMax[i] = rightMax[i+1];
            } else {
                rightMax[i] = height[i];
            }
        }
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }
};

int main() {
    Solution s;
    vector<int> v {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << s.trap(v);
    return 0;
}
