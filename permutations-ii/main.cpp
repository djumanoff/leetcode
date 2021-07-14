#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void print_arr(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
};

void print_2darr(vector<vector<int> > v) {
    for (int i = 0; i < v.size(); i++) {
        print_arr(v[i]);
    }
    cout << endl;
};

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        permute(nums, 0);
        return ans;
    }
    
    void permute(vector<int>& nums, int lvl) {
        if (lvl == nums.size()) {
            ans.push_back(nums);
            return ;
        }
        unordered_set<int> s;
        for (int i = lvl; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            swap(nums[lvl], nums[i]);
            permute(nums,lvl+1);
            swap(nums[lvl], nums[i]);
        }
    }
};


int main() {
    Solution s;
    vector<int> v{1,1,2};
    print_2darr(s.permuteUnique(v));
    return 0;
}
