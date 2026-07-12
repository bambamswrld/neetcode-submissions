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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);

        int idx = std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        std::vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + idx);
        std::vector<int> rightPre(preorder.begin() + 1 + idx, preorder.end());
        std::vector<int> leftIn(inorder.begin(), inorder.begin() + idx);
        std::vector<int> rightIn(inorder.begin() + idx + 1, inorder.end());

        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};
