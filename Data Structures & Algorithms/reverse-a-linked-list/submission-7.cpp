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
        unique_ptr<ListNode> ans = make_unique<ListNode>();

        ListNode* itr = head;
        while(itr != nullptr) {
            ListNode* temp = itr;
            itr = itr->next;
            temp->next = ans->next;
            ans->next = temp;
        }

        return ans->next;
    }
};
