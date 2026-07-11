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
private:
    int height(TreeNode* node)
    {
        if(node)
        {
            return 1 + std::max(height(node->left), height(node->right));
        }
        else 
            return 0;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        int rightRes = height(root->right);
        int leftRes = height(root->left);

        if(std::abs(leftRes - rightRes) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
