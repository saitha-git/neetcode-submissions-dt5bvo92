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
    ListNode* findMiddleNode(ListNode* head) {
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        while(fastPtr->next && fastPtr->next->next){
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        ListNode* right = slowPtr->next;
        slowPtr->next = nullptr;
        return right;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode temp;
        ListNode* mergeNode = &temp;
        while(left && right) {
            ListNode* leftNode = left;
            ListNode* rightNode = right;
 
            if(leftNode->val <= rightNode->val) {
                mergeNode->next = leftNode;
                left = left->next;
            } else {
                mergeNode->next = rightNode;
                right = right->next;
            }

            mergeNode = mergeNode->next;
        }

        if(left) mergeNode->next = left;

        if(right) mergeNode->next = right;

        return temp.next;
    }

    ListNode* dfs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* middle = findMiddleNode(head);
        ListNode* left  = dfs(head);
        ListNode* right = dfs(middle);
        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        return dfs(head);
    }
};
