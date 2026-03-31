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
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };   
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
        // push all the start nodes
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        ListNode dummy;
        ListNode* ans = &dummy;

        while (!minHeap.empty()) {
            auto top = minHeap.top();
            minHeap.pop();

            ans->next = top;
            ans = ans->next;
            if(top->next)
                minHeap.push(top->next);
        }

        return dummy.next;
    }
};
