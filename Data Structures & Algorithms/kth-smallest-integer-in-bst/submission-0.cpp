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
    stack<int> _stack;

    void dfs(TreeNode* node,int k)
    {
        if (node == nullptr)
        {
            return;
        }
        
        cout << node->val << endl;
        dfs(node->left,k);
        
        if (_stack.size() != k)
        {
            _stack.push(node->val);
        }
        else
        {
            return;
        }
        
        dfs(node->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return _stack.top();
    }
};

