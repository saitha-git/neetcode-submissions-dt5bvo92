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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* r = head;
        
        while(n != 0)
        {
            r = r->next;
            n--;
        }

        ListNode* l = head;
        ListNode* prev = nullptr;
        while(r)
        {
            prev = l;
            l = l->next;
            r = r->next;
        }

        if( l == head)
        {
            return head->next;
        }
        else if (prev)
        {
            prev->next = l->next;
            return head;
        }

    }
};


