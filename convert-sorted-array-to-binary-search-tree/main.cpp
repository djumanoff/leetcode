#include <vector> 

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
    
    TreeNode* solve(vector<int>& nums, int l, int r) {
        if (l == r) {
            return new TreeNode(nums[l]);
        }
        if (r - l == 1) {
            TreeNode* node = new TreeNode(nums[r]);
            node->left = new TreeNode(nums[l]);
            return node;
        }
        int m = (l + r)/2;
        
        TreeNode* node = new TreeNode(nums[m]);
        node->left = solve(nums, l, m - 1);
        node->right = solve(nums, m + 1, r);
        
        return node;
    }
};

int main() {
    Solution s;

    vector<int> nums {-10,-3,0,5,9};

    s.sortedArrayToBST(nums);

    return 0;
}
