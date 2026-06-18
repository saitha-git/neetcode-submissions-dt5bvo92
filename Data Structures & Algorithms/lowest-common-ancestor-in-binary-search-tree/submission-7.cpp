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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();

            if(p->val < node->val && q->val < node->val) {
                stk.push(node->left);
            } else if(p->val > node->val && q->val > node->val) {
                stk.push(node->right);
            } else {
                return node;
            }
        }
    }
};
