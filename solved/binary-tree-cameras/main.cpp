#include <iostream>

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
    int count = 0;

    int minCameraCover(TreeNode* root) {
        return dfsWithcount(root) == -1 ? ++count : count;
    }

    int dfsWithcount(TreeNode* root) {
        if (root == nullptr) {
            return 1;
        }
        int left = dfsWithcount(root->left);
        int right = dfsWithcount(root->right);
        if (left == -1 || right == -1) {
            count++;
            return 0;
        } else if (left == 0 || right == 0) {
            return 1;
        } else {
            return -1;
        }
    }
};

int main() {
    return 0;
}
