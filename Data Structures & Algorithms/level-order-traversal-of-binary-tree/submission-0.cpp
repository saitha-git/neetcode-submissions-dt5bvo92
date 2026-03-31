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
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;

        if(root)
            q.push({root,0});
        
        while(!q.empty())
        {
            
            TreeNode* front = q.front().first;
            int level = q.front().second;
            
            if(level == ans.size()) // If the level does not exist in ans, add a new vector
                ans.push_back(vector<int>());
            
            ans[level].push_back(front->val);
            if(front->left)
                q.push({front->left,level+1});
            if(front->right)
                q.push({front->right,level+1});
            q.pop();
        }
 
        return ans;
    }
};

