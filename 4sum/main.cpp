#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void print_arr(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
};

void print_2darr(vector<vector<int> > nums) {
    for (int i = 0; i < nums.size(); i++) {
        print_arr(nums[i]);
    }
    cout << endl;
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        int n = nums.size();
        sort(nums, 0, n-1);

        for (int i = 0; i < n-3; i++) {
            for (int j = i+1; j < n-2; j++) {
                int sum1 = nums[i] + nums[j];
                int diff = target - sum1;

                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    int sum2 = nums[left] + nums[right];
                    if (sum2 == diff) {
                        vector<int> v {nums[i], nums[j], nums[left], nums[right]};
                        result.push_back(v);
                        while (left < right && nums[left] == v[2]) left++;
                        while (left < right && nums[right] == v[3]) right--;
                    } else if (sum2 < diff) {
                        left++;
                    } else {
                        right--;
                    }
                }
                while (i+1 < n-3 && nums[i+1]==nums[i]) i++;
                while (j+1 < n-2 && nums[j+1]==nums[j]) j++;
            }
        }
        // print_arr(nums);
        print_2darr(result);
        return result;
    }
    
    void sort(vector<int>& nums, int i, int j) {
        if (j-i <= 0) {
            return ;
        }
        int pi = (j+i)/2;
        int left = i;
        int right = j;
        swap(nums, pi, right);
        for (int k = i; k < right; k++) {
            if (nums[k] < nums[right]) {
                swap(nums, k, left);
                left++;
            }
        }
        swap(nums, left, right);
        
        sort(nums, i, left);
        sort(nums, left+1, j);
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};

int main() {
    Solution s;

    vector<int> v1 {1,0,-1,0,-2,2};
    s.fourSum(v1, 0);

    vector<int> v2 {2, 2, 2, 2, 2};
    s.fourSum(v2, 8);

    return 0;
}
