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
        ListNode dummy;
        ListNode* ans = &dummy;
        
        while (true)
        {
            int minIndex = -1;
            for(int i=0; i<lists.size(); i++)
            {
                if (lists[i])
                {   
                    if ( minIndex == -1 || lists[minIndex]->val > lists[i]->val) 
                    {
                        minIndex = i;
                    }
                }
            }
            if (minIndex == -1) break;
            ans->next = lists[minIndex];
            ans = ans->next;
            lists[minIndex] = lists[minIndex]->next;
        }

        return dummy.next;
    }
};
