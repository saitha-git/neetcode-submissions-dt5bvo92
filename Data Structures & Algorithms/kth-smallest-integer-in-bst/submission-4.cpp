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

    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
       
        TreeNode* curr = root;
        while(!s.empty() || curr) {

            while(curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            
            auto top = s.top();
            if(--k == 0) {
                return top->val;
            }
            s.pop();
            
            curr = top->right;
        }

        return curr->val;    
    }
};
