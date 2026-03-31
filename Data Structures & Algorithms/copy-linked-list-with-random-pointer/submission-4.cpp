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
        
        unordered_map<Node*, Node*> lut;

        Node* itr = head; 
        Node ans(0);
        Node* curr = &ans;
        
        while(itr) {
            if (lut.find(itr) == lut.end()) {
                lut[itr] = new Node(itr->val);
            }
            curr->next   = lut[itr]; 

            if (itr->next) {
                if (lut.find(itr->next) == lut.end()) {
                    lut[itr->next] = new Node(itr->next->val);
                }
                curr->next->next = lut[itr->next];
            } 

            if(itr->random) {
                if (lut.find(itr->random) == lut.end()) {
                    lut[itr->random] = new Node(itr->random->val);
                }
                curr->next->random = lut[itr->random];
            }
            
            itr  = itr->next;
            curr = curr->next;
        }

        return ans.next;
    }
};
