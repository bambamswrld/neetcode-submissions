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
    void dfs(TreeNode* node, vector<int>& nodeList)
    {
        if(!node)
            return;

        nodeList.push_back(node->val);
        dfs(node->left, nodeList);
        dfs(node->right, nodeList);

    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        std::vector<int> nodeList1, nodeList2;

        dfs(root1, nodeList1);
        dfs(root2, nodeList2);

        for(int a : nodeList1)
        {
            for(int b : nodeList2)
            {
                if(a + b == target)
                    return true;
            }
        }
        return false;
    }
};
