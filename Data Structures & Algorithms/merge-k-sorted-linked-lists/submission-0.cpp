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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode  dummy;
        ListNode* node = &dummy;
        node->next = nullptr;

        for(auto list: lists)
        {
             node->next = mergeLists(node->next,list);
        }

        return dummy.next;
    }

private:
    ListNode* mergeLists(ListNode* list1,ListNode* list2)
    {
        ListNode  dummy;
        ListNode* node = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                node->next = list1;
                list1 = list1->next;
                
            }
            else
            {
                node->next = list2;
                list2 = list2->next;
                
            }
            node = node->next;
            node->next = nullptr;
        }

        if (list1)
        {
            node->next = list1;
        }
        
        if (list2)
        {
            node->next = list2;   
        }

        return dummy.next;
    }

};

