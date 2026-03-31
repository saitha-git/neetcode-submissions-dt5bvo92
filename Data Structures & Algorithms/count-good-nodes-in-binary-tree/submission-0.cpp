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
    
    int dfs(TreeNode* node, int max, int count)
    {
        if(node == nullptr)
        {
            return count;
        }

        if (node->val >= max)
        {
            max = node->val;
            cout << max << endl;
            ++count;
        }
        count = dfs(node->left,max,count);
        count = dfs(node->right,max,count);

        return count;
    }
    
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN,0);
    }
};
