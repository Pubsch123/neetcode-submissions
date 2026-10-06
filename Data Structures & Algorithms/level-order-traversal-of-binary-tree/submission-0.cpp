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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(cur);
        vector<vector<int>> ans;
        if(!root)
            return ans;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> sample;
            while(size--){
                TreeNode* ptr = q.front();
                q.pop();
                sample.push_back(ptr->val);
                if(ptr->left)
                    q.push(ptr->left);
                if(ptr->right)
                    q.push(ptr->right);
            }
            ans.push_back(sample);
        }
        return ans;
    }
};
