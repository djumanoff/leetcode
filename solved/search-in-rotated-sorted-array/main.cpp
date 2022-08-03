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
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        } 
        if (nums[0] < nums[n-1]) {
            return binarySearch(nums, target, 0, n-1);
        }
        return binarySearchRotated(nums, target, 0, n-1);
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        int result = -1;
        while (left <= right) {
            int middle = (left+right)/2;
            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] > target) {
                right = middle-1;
            } else {
                left = middle+1;
            }
        }
        return result;
    }

    int binarySearchRotated(vector<int>& nums, int target, int left, int right) {
        int result = -1;
        while (left <= right) {
            int middle = (left+right)/2;
            cout << left << " " << right << endl;
            // found
            if (nums[middle] == target) {
                return middle;
            // going to right
            } else if (
                (nums[middle] <= nums[right] && nums[middle] < target && target <= nums[right]) ||
                (nums[middle] > nums[right] && nums[middle] < target && nums[left] < target) ||
                (nums[middle] > nums[right] && nums[middle] > target && nums[left] > target)
            ) {
                left = middle+1;
            } else {
            // going to left
                right = middle-1;
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    // vector<int> v {5,1,2,3,4};
    // cout << s.search(v, 1) << endl;

    // vector<int> v1 {5,1,3};
    // cout << s.search(v1, 3) << endl;

    vector<int> v2 {3,5,1};
    cout << s.search(v2, 3) << endl;

    return 0;
}
