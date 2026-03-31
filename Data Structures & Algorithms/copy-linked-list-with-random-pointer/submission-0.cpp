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
        unordered_map<Node*,Node*> nodeLUT;
        Node dummy(0);
        Node* res = &dummy;
        static int i;

        while (head)
        {
#if 1            
            if(nodeLUT.find(head) != nodeLUT.end())
            {
                res->next = nodeLUT[head];
                cout << "1" << ":" << res->next->val << endl;
            }
            else
#endif
            {
                res->next = new Node(head->val);
                nodeLUT[head] = res->next;
                cout << "2" << ":" << res->next->val << endl;
            }
            
            if (head->random != nullptr)
            {
                if(nodeLUT.find(head->random) != nodeLUT.end())
                {
                    res->next->random = nodeLUT[head->random];
                    cout << "3" << ":" << res->next->random->val << endl;
                }
                else
                {
                    res->next->random = new Node(head->random->val);
                    cout << "4" << ":" << res->next->random->val << endl;
                    nodeLUT[head->random] = res->next->random;
                }
            }            
        
            res  = res->next;
            head = head->next;
        }
        res->next = nullptr;

        return dummy.next; 
    }
};