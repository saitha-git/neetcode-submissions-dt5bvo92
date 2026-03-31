class Solution {
public:
    typedef pair<int, int> PII;

    int findKthLargest(vector<int>& nums, int k) {
        auto compare = [](PII a, PII b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        };
        
        priority_queue<PII, vector<PII>, decltype(compare)> pq;

        for(int i=0; i<nums.size(); i++) {
            pq.push(pair{nums[i], i});

            if(pq.size() > k) {
                pq.pop();
            }
        }
        auto ans = pq.top();
        return ans.first;
    }
};
