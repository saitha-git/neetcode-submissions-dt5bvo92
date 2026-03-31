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
        ListNode dummy;
        ListNode* node = &dummy;

        int carry = 0;
        int temp;
        while (l1 || l2)
        {
            if ( l1 && l2)
            {
                temp = carry + l1->val + l2->val;
            }
            else if (l1)
            {
                temp = carry + l1->val;
            }
            else
            {
                temp = carry + l2->val;
            }
            
            if(temp<=9)
            {
                node->next = new ListNode(temp);
                carry = 0;
            }
            else
            {
                node->next = new ListNode(temp%10);
                carry = temp/10;
            }

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            node = node->next;
        }

        if (carry)
           node->next = new ListNode(1); 

        return dummy.next;
    }
};



