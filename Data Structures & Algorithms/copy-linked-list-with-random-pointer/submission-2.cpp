/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap;
        Node* node = head;
        
        while(node)
        {
            nodeMap[node] = new Node(node->val);
            node = node->next;
        }

        node = head;
        Node dummy(0);
        Node* tailNode = &dummy;

        while(node)
        {
            tailNode->next   = nodeMap[node];
            if (node->random)
                tailNode->next->random = nodeMap[node->random];
            
            tailNode = tailNode->next;
            node     = node->next;
        }

        return dummy.next;
    }
};
