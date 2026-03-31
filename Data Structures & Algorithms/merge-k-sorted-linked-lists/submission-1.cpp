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
        int n = lists.size();

        cout << "n:" << n << endl;
        if ( n == 0)
        {
            return nullptr;
        }

               
        while (n != 1)
        {
            int l = 0;
            int r = n-1;
            int i = 0;
            
            
            while (l < r)
            {
                cout << "l:" << l << "r:" << r << "n:" << n  << endl;
                lists[i++] = mergeLists(lists[l],lists[r]);
                cout << lists[i]->val << endl;
                l++;
                r--;
            }
            n = (n+1)/2;
        }

        return lists[0];
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

