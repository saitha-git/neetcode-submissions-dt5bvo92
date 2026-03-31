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

        if(!head)
            return head;

        vector<ListNode*> vec;
        ListNode* node = head;
        while(node)
        {
            vec.push_back(node);
            node = node->next;
        }

        int removeIndex = vec.size() - n; 

        if(0 == removeIndex)
        {
            return head->next;
        }
        if (removeIndex+1 <= vec.size()-1)
            vec[removeIndex-1]->next = vec[removeIndex+1];
        else
            vec[removeIndex-1]->next = nullptr;

        return head;

    }
};
