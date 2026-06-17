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
    typedef pair<int, ListNode*> pII;

    struct Compare {
        bool operator()(pII a, pII b) { return a.first > b.first; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pII, vector<pII>, Compare> minHeap;
        int size = lists.size();

        vector<ListNode*> tracker(size, nullptr);
        vector<bool> processed(size, false);
        int processedCount = 0;

        for (int i = 0; i < size; i++) {
            ListNode* list = lists[i];
            tracker[i] = list;
        }

        ListNode ans = ListNode();
        ListNode* itr = &ans;


        while (processedCount != size) {
            for (int i = 0; i < size; i++) {
                if (!processed[i]) {
                    ListNode* node = tracker[i];

                    if (node != nullptr) {
                        minHeap.push(pII{node->val, node});
                        tracker[i] = tracker[i]->next;
                    } else {
                        processed[i] = true;
                        processedCount++;
                    }
                    
                }
            }

            if (!minHeap.empty()) {
                itr->next = minHeap.top().second;
                minHeap.pop();
                itr = itr->next;
            }
        }

        while (!minHeap.empty()) {
            itr->next = minHeap.top().second;
            minHeap.pop();
            itr = itr->next;
        }

        itr->next = nullptr;
        return ans.next;
    }
};
