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
    ListNode* revHead;
    ListNode* reverseListRec(ListNode* node) {
        ListNode* retNode = nullptr;

        if (nullptr == node->next )
        {
            return revHead = node;
        }
        retNode = reverseListRec(node->next);
        node->next = nullptr;
        retNode->next = node;
        return node;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head)
        {
            return nullptr;
        }
        reverseListRec(head);
        return revHead;
    }
};
