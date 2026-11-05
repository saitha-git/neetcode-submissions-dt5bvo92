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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode temp(0);
        ListNode* ans = &temp;

        int carry = 0;
        while( l1 || l2)
        {
            int v1 = l1 != nullptr ? l1->val : 0;
            int v2 = l2 != nullptr ? l2->val : 0;

            int sum = v1+v2+carry; 
            carry = sum/10; // store sum%10
            ans->next = new ListNode(sum%10);
            ans = ans->next;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if(carry != 0) {
            ans->next = new ListNode(carry);
        }

        return temp.next;
    }
};
