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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sortedList;
        ListNode* head = nullptr;
        while( (list1 != nullptr) && (list2 != nullptr))
        {
            if(min(list1->val, list2->val) == list1->val)
            {
                sortedList->next = list1;
                list1 = list1->next;
            }
            else
            {
                sortedList->next = list2;
                list2 = list2->next;
            }

             if (head == nullptr)
             {
                head = sortedList->next;
             }

             sortedList = sortedList->next;
        }

        ListNode* list = nullptr;
        if (list1 != nullptr)
        {
            list = list1;
        }
        else if (list2 != nullptr)
        {
            list = list2;
        }

        while (list != nullptr)
        {
            sortedList->next = list;

            if (head == nullptr)
            {
                head = sortedList->next;
            }

            sortedList = sortedList->next;
            list = list->next;
        }

        return head;
    }


};
