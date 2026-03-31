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
    ListNode* reverse(ListNode* head) {
        ListNode  dummy;
        ListNode* node = &dummy;

        dummy.next = nullptr;
        while(head)
        {
            ListNode* temp = head->next;
            head->next = node->next;
            node->next = head;
            head = temp;
            //cout << node->next->val << endl;
        }

        return dummy.next;
    }


    ListNode* merge(ListNode* list1,ListNode* list2) {
        ListNode  dummy;
        ListNode* node = &dummy;

        dummy.next = nullptr;
        while(list2 && list1)
        {
            node->next = list1;
            node = node->next;
            list1 = list1->next;
    
            node->next = list2;
            node = node->next;
            list2 = list2->next;
        }

        if(list2)
        {
            node->next = list2;
        }

        return dummy.next;
    }
    
    
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* prev = slow;
        // 1. Find the middle node.
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

#if 1   
        if(head != slow)
        {             
            ListNode* reverseL = nullptr;
            // 2. Reverse the second half
            reverseL = reverse(slow);
            ListNode* temp = reverseL;

            while(temp)
            {
                cout << temp->val <<" ";
                temp = temp->next;
            }
            cout << endl;

            //3. Merge the two lists
            head = merge(head,reverseL);
        }
#endif
    }
};



