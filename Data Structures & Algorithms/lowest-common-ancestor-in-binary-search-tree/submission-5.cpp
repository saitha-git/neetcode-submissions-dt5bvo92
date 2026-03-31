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
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q) {

        if (node && p->val < node->val && q->val < node->val) {
            return  dfs(node->left,p, q);    
        }
        else if (node && p->val > node->val && q->val > node->val) {
            return dfs(node->right, p, q);
        }
        else {
            return node;
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
