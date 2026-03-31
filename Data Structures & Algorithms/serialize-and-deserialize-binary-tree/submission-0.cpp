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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        // bfs
        if (!root) {
            s += "null";
            s += ","; 
            cout << s << endl;
            return s;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (front) {
                s += to_string(front->val);
                q.push(front->left);
                q.push(front->right);
            } else {
                s += "null";
            }
            s += ',';

        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        cout << val << endl;
        if (val == "null") {
            cout << "out" << endl;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while (getline(ss, val, ',')) {
            auto front = q.front();
            q.pop();
            if (val != "null") {
                front->left = new TreeNode(stoi(val));
                q.push(front->left);
            }
            getline(ss, val, ',');
            if (val != "null") {
                front->right = new TreeNode(stoi(val));
                q.push(front->right);
            }
        }
        return root;
    }
};
