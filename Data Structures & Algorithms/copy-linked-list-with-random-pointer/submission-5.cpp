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
        // oldNode, newNode
        unordered_map<Node*, Node*> mapping;
        Node temp(0);
        Node* ans = &temp;
        mapping[nullptr] = nullptr;
        
        while(head != nullptr) {
            auto itr = mapping.find(head);
            
            if(itr != mapping.end()){
                ans->next = itr->second;
            } else {
                ans->next = new Node(head->val);
                mapping[head] = ans->next;
            }
            
            itr = mapping.find(head->random);
            
            if(itr != mapping.end()){
                ans->next->random = itr->second;
            } else {
                ans->next->random = new Node(head->random->val);
                mapping[head->random] = ans->next->random;
            }

            head = head->next;
            ans  = ans->next;
        }

        return temp.next;
    }
};
