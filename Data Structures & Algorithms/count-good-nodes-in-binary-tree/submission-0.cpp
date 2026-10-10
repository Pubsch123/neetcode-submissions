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

    int solve(TreeNode* root, int value) {
        if(!root) return 0;
        int c1 = solve(root->left,max(value,root->val)) + solve(root->right,max(value,root->val));
        if(root->val >= value)
        return 1 + c1;
        else
        return c1;
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        return solve(root,INT_MIN);
    }
};
