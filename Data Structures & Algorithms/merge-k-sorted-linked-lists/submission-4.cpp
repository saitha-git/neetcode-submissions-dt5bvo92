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

typedef struct pair<int, ListNode*> intPair;

class _greater
{
public:
    bool operator()(intPair& below, intPair& above)
    {
        if ( above.first < below.first )
        {
            return true;
        }
        
        return false;
    }
};

class Solution {
public:


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<intPair, vector<intPair>, _greater > minHeap;
        ListNode dummy(0);
        ListNode* ans = &dummy;
        for(auto const& list:lists)
        {
            minHeap.push( {list->val, list} );
        }
        
        while(!minHeap.empty())
        {
            ans->next = minHeap.top().second;
            minHeap.pop();
            if(ans->next->next)
            {
                minHeap.push( {ans->next->next->val, ans->next->next} );
            }
            ans = ans->next;
        }

        return dummy.next;
    }
};
