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
    void reorderList(ListNode* head) {
        vector<ListNode*>  vec;
        while(head) {
            vec.push_back(head);
            head = head->next;
        }
        cout << vec.size() << endl;
        ListNode dummy;
        ListNode* ans = &dummy;
        int l = 0;
        int r = vec.size()-1;
        while(l < r) {
            ans->next = vec[l];
            ans = ans->next;
            
            ans->next = vec[r];
            ans = ans->next;
            
            l++;
            r--;
        }

        // odd case
        if(l == r) {
            ans->next = vec[l];
            ans = ans->next;
        }
        ans->next = nullptr;

        head = dummy.next;
    }
};
