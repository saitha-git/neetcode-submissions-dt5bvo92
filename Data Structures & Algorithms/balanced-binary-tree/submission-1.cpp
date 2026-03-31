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

    int dfs(TreeNode* root, bool& res)
    {
        if(root == nullptr)
            return 0;

        if (res)
        {
            int left  = dfs(root->left,res);
            int right = dfs(root->right,res);

            if( !( (abs(left-right) == 0) || (abs(left-right) == 1 ) ) )
            {
                cout<< "left:" << left << "right:" << right << endl;
                res = false;
            }
            
            return 1+max(left,right);
        }

    }
    
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
};
