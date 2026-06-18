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
    typedef pair<ListNode*, int> pNI;

    struct Compare {
        bool operator()(pNI a, pNI b) { return a.second > b.second; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pNI, vector<pNI>, Compare> minHeap;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                minHeap.push(pNI{lists[i], lists[i]->val});
            }
        }

        ListNode ans = ListNode(0);
        ListNode* itr = &ans;
        while (!minHeap.empty()) {
            itr->next = minHeap.top().first;
            minHeap.pop();
            if (itr->next->next != nullptr) {
                minHeap.push(pNI{itr->next->next, itr->next->next->val});
            }
            itr = itr->next;
        }

        itr->next = nullptr;
        return ans.next;
    }
};
