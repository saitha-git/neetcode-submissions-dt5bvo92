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
        
        int minVal; 
        int minIdx = 0;
        int n = lists.size();
        int count;

#if 1           
        while (true)
        {
            count = 0;
            minIdx = -1;
            minVal = INT_MAX;
            for(int i=0; i<n; ++i)
            {
                if (lists[i] != nullptr)
                {
                    minVal = min(minVal, lists[i]->val);
                    if (minVal == lists[i]->val)
                    {
                        minIdx = i;
                    }
                    count++;
                    cout << "minIdx:" << minIdx << endl;
                }
            }

            if (-1 != minIdx)
            {
                node->next = lists[minIdx];
                node = node->next; 
                lists[minIdx] = lists[minIdx]->next;
                node->next = nullptr;
                    
                if (lists[minIdx])
                {
                    cout << lists[minIdx]->val << endl;
                }
            }
            
            if (0 == count)
            {
                break;
            }
        }
#endif
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

