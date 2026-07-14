/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
int res = INT_MIN;
private:
    int dfs(TreeNode* node)
    {
        if(!node)
            return 0;

        int leftMax = std::max(dfs(node->left), 0);
        int rightMax = std::max(dfs(node->right), 0);

        int peak = node->val + leftMax + rightMax;

        res = std::max(res, peak);

        return node->val + std::max(leftMax, rightMax);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
