#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        if (l == 1) {
            return true;
        }
        int i = 0;

        while (i < l) {
            if (nums[i] == 0 && i < l-1) {
                return false;
            } else if (nums[i] == 0 && i == l-1) {
                return true;
            }
            int start = i;
            int end = i + nums[i];
            if (end >= l - 1) {
                return true;
            }
            int k = max(nums, start, end);
            if (i == k) {
                return false;
            }
            i = k;
        }
        return true;
    }

private: 
    int max(vector<int>& nums, int i, int j) {
        int max_i = 0;
        int max = 0;
        j = j >= nums.size() ? nums.size()-1 : j;
        if (j - i <= 0) {
            return max_i;
        }
        for (int k = i; k <= j; k++) {
            if (k + nums[k] > max) {
                max = k + nums[k];
                max_i = k;
            }
        }
        return max_i;
    }
};


int main() {
    Solution s;
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(0);
    // v.push_back(0);

    // vector<int> v;
    // v.push_back(2);
    // v.push_back(0);
    // v.push_back(0);
    // v.push_back(0);

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(1);
    // v.push_back(0);
    // v.push_back(4);

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(0);
    // v.push_back(1);
    // v.push_back(1);

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);

    // vector<int> v;
    // v.push_back(5);
    // v.push_back(9);
    // v.push_back(3);
    // v.push_back(2);
    // v.push_back(1);
    // v.push_back(0);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(3);
    // v.push_back(1);
    // v.push_back(0);
    // v.push_back(0);

    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(4);
    
    cout << s.canJump(v) << endl;
}

