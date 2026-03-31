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
    bool _isValidBST(TreeNode* node, int min, int max)
    {
        bool res = true;

        cout << "node:" << node->val << "min:" << min << "max:" << max << endl;
        if (nullptr == node)
        {
            return res;
        }

        if ( (min < node->val) && (node->val < max))
        {

        }
        else
        {
            return res = false;
        }

        TreeNode* left  = node->left;
        TreeNode* right = node->right;

        if (res && left)
        {
            res = res && _isValidBST(node->left, min, node->val);
        }

        if (res && right)
        {
            res = res && _isValidBST(node->right, node->val, max);
        }
            
        return res;
    }
    
    bool isValidBST(TreeNode* root) {
        _isValidBST(root, INT_MIN, INT_MAX);
    }
};
