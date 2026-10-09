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
    bool isValidBST(TreeNode* root) {
        return validBST(root,INT_MIN,INT_MAX);
    }
    bool validBST(TreeNode* root, int left, int right)
    {
        if(!root) return true;
        if(left>=root->val || right<=root->val) return false;
        return validBST(root->left, left, root->val) && validBST(root->right, root->val,right);
    }
};
