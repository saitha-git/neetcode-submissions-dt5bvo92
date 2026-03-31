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
    int count;
    bool dfs(TreeNode* root, int k, int& ans) {
        if (root == nullptr) {
            return false;
        }
        if (dfs(root->left,k, ans)) return true;
        count++;
        if (count == k){
            ans = root->val;
            return true;
        }
        return dfs(root->right,  k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        int ans;
        dfs(root, k, ans);
        return ans;
    }
};
