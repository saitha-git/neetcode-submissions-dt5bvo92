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
    bool res = false;

    bool isSameTree(TreeNode* root, TreeNode* subRoot) {

        if(root && subRoot && root->val == subRoot->val)
        {
            return (isSameTree(root->left,subRoot->left) && isSameTree(root->right,subRoot->right));
        }
        else if(!root && !subRoot)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

     
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if (isSameTree(root, subRoot))
            return true;
        else
        {
            if(root->left)
            {
                cout << root->left->val << endl;
                res = isSubtree(root->left,subRoot);
            }

            if(!res && root->right)
            {
                cout << root->right->val << endl;
                res = isSubtree(root->right,subRoot);
            }

            cout << "res:" << res << endl;
            return res;        
        }
    }
    
};
