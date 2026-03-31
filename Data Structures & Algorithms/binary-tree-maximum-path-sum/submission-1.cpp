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
    int dfs(TreeNode* root, int& _maxPathSum)
    {
        if(!root)
            return 0;
        

        auto l_maxPathSum = dfs(root->left, _maxPathSum);
        auto r_maxPathSum = dfs(root->right, _maxPathSum);
        _maxPathSum = max( _maxPathSum,
                            max ( max( root->val,
                                 root->val+l_maxPathSum),
                            max( root->val+r_maxPathSum,
                                root->val+l_maxPathSum+r_maxPathSum) ));
        return max( 0,
                    max( max ( root->val,
                          root->val+l_maxPathSum ),
                    root->val+r_maxPathSum) );
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int _maxPathSum = root->val;
        dfs(root, _maxPathSum);
        return _maxPathSum;
    }
};
