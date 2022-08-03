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
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            if (nums[l] == val) {
                swap(nums, l, r);
                r--;
            } else {
                l++;
            }
        }
        int s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) s++; else break;
        }
        return s;
    }

    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            while (r < nums.size() && nums[l] == nums[r]) r++;
            if (r >= nums.size()) break;

            if (r - l <= 1) {
                l++;
                continue;
            }
            l++;
            swap(nums, l, r);
            r++;
        }
        cout << l << " " << r << endl;
        return l+1;
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }


    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; ++i) {
            for (int j = i+1; j < arr.size(); ++j) {
                if (arr[i] * 2 == arr[j]) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> v {3, 2};

    // auto it = v.begin();
    // cout << *it <<endl;
    // it = v.insert(it+1, 0);

    // cout << *it <<endl;
    // it++;
    // cout << *it <<endl;
    // it++;
    // cout << *it <<endl;

    // cout << s.removeElement(v, 3) << endl;
    // print_arr(v);

    // vector<int> v1 {0,0,1,1,1,2,2,3,3,4};
    // cout << s.removeDuplicates(v1) << endl;
    // print_arr(v1);

    vector<int> v2 {1,1};
    cout << s.removeDuplicates(v2) << endl;
    print_arr(v2);

    return 0;
}
