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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        
        while (i < m || j < n) {
            if (nums1[i] >= nums2[j]) {
                shiftFrom(i, nums1);
                nums1[i] = nums2[j];
                j++;
                i++;
            } else {
                i++;
                nums1[i] = nums2[j];
                j++;
            }
        }
    }
    
    void shiftFrom(int start, vector<int>& nums) {
        if (start >= nums.size() - 1) {
            return ;
        }
        for (int i = nums.size() - 1; i > start; --i) {
            nums[i] = nums[i-1];
        }
    }
};

int main() {
    Solution s;

    // vector<int> v1 {1,2,3,0,0,0};
    // vector<int> v2 {2,5,6};

    // s.merge(v1, 3, v2, 3);

    // vector<int> v1 {2,0};
    // vector<int> v2 {1};

    // s.merge(v1, 1, v2, 1);

    vector<int> v1 {4,0,0,0,0,0};
    vector<int> v2 {1,2,3,5,6};
    s.merge(v1, 1, v2, 5);

    print_arr(v1);

    return 0;
}
