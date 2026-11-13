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
    using PIN = pair<int, ListNode*>;
    
    // return true there is a swap
    struct Compare{
        bool operator()(PIN& a, PIN& b){
            return a.first > b.first;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* ans = &dummy;
        priority_queue<PIN, vector<PIN>, Compare> pq;

        for(auto node : lists) {
            if(node != nullptr)
                pq.push({node->val, node});
        }

        while(!pq.empty()) {
            auto top = pq.top();
            auto topNode = top.second;
            pq.pop();
            ans->next = topNode;
            if(topNode->next != nullptr)
                pq.push({topNode->next->val, topNode->next});

            ans = ans->next;
        }
        
        return dummy.next;
    }
};
