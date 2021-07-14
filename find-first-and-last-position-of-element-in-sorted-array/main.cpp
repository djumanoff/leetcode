#include <iostream>
#include <string>
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();

        if (n == 0) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        result.push_back(findFirst(nums, target, 0, n-1));
        result.push_back(findLast(nums, target, 0, n-1));

        return result;
    }

    int findFirst(vector<int>& nums, int target, int i, int j) {
        if (j - i <= 1) {
            if (nums[i] == target) {
                return i;
            }
            if (nums[j] == target) {
                return j;
            }
            return -1;
        }
        int middle = (i+j)/2;
        if (nums[middle] == target) {
            if (middle == 0) {
                return middle;
            }
            if (nums[middle-1] != target) {
                return middle;
            }
            return findFirst(nums, target, i, middle);
        } else if (nums[middle] < target) {
            return findFirst(nums, target, middle, j);
        } else {
            return findFirst(nums, target, i, middle);
        }
    }

    int findLast(vector<int>& nums, int target, int i, int j) {
        if (j - i <= 1) {
            if (nums[j] == target) {
                return j;
            }
            if (nums[i] == target) {
                return i;
            }
            return -1;
        }
        int middle = (i+j)/2;
        if (nums[middle] == target) {
            if (middle == (nums.size()-1)) {
                return middle;
            }
            if (nums[middle+1] != target) {
                return middle;
            }
            return findLast(nums, target, middle, j);
        } else if (nums[middle] < target) {
            return findLast(nums, target, middle, j);
        } else {
            return findLast(nums, target, i, middle);
        }
    }
};

int main() {
    Solution s;
    vector<int> v1 {5,7,7,8,8,10};
    print_arr(s.searchRange(v1, 8));

    // vector<int> v1 {5,7,7,8,8,10};
    print_arr(s.searchRange(v1, 6));

    return 0;
}
