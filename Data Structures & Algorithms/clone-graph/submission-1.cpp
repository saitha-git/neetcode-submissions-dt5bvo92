/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        unordered_map<Node*, Node*> oldToNew;

        if (node == nullptr)
            return nullptr;

        oldToNew[node] = new Node(node->val);
        q.push(node);
        
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();

            for(auto nbr : front->neighbors)
            {
                if (oldToNew.find(nbr) != oldToNew.end())
                {
                    oldToNew[front]->neighbors.push_back(oldToNew[nbr]);
                }
                else
                {
                    oldToNew[nbr] = new Node(nbr->val);
                    oldToNew[front]->neighbors.push_back(oldToNew[nbr]);
                    q.push(nbr);
                }

            }
        }

        return oldToNew[node];
    }
};
