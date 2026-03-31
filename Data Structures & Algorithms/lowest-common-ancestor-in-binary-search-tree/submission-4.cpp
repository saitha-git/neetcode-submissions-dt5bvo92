class Solution {
public:
    TreeNode* ans;
    bool _lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }

        bool left = _lowestCommonAncestor(root->left, p, q) ;
        bool right = _lowestCommonAncestor(root->right, p, q);
        bool mid = (root->val == p->val || root->val == q->val) ? 1 : 0;

        //cout << (root == p) << (root == q) << endl;
        
        if (left + mid + right >= 2) {
            cout << root->val << endl;
            ans = root;
        }
        //std::cout << "root: " << root->val << ", left: " << left << ", right: " << right << ", mid: " << mid << std::endl;
        return left + mid + right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        _lowestCommonAncestor(root, p, q);
        return ans;
    }
};
