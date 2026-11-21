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
    ListNode* reverseList(ListNode* head) {
        ListNode* itr = nullptr;
        
        while(head) {
            ListNode* node = head;
            head = head->next;

            node->next = nullptr;
            if(itr)
                node->next = itr;
            
            itr = node;
        }

        return itr;
    }
};
