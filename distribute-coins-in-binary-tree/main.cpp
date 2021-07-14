#include <iostream>
#include <cmath>

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
    int numOfMoves = 0;

    int distributeCoins(TreeNode* root) {
        dfs(nullptr, root);
        return numOfMoves;
    }

    void dfs(TreeNode* root, TreeNode* child) {
        if (child == nullptr) {
            return ;
        }

        dfs(child, child->left);
        dfs(child, child->right);

        while (child->val < 1) {
            numOfMoves++;
            root->val--;
            child->val++;
        }
        while (child->val > 1) {
            numOfMoves++;
            root->val++;
            child->val--;
        }
    }
};

int main() {
    Solution s;
    return 0;
}
