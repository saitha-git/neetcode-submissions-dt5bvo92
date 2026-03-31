/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode dummy;
    ListNode* node = &dummy;
    ListNode* tail;
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* l;
        ListNode* r;
        ListNode* prev;     
        node->next = nullptr;

        r = head;
        while (r)
        {
            
            int count = 0;
            l = r;
            while (r && (count != k))
            {
                prev = r;
                r = r->next;
                count++;
            }

            cout << "l:" << l->val << "r:" << prev->val <<"count:" <<count << endl;
            prev->next = nullptr; 
#if 1           
            if (count ==  k)
            {
                reverse(l);
            }
            else
            {
                tail->next = l;
            }
#endif
         }

        return dummy.next;
    }

private:
    void reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
       
        do
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            
            if (next)
                curr = next;
        }while (next);   

        if ( prev )
            cout << "curr:" << prev->val << endl; 

        if (!node->next)
            node->next = prev;
        else
            tail->next = prev;

        tail = head;
    }

};
