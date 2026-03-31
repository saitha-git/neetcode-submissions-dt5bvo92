class Solution {
public:
    typedef pair<int, int> PII;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        for (auto num : nums) {
            freq[num]++;
        }
        auto cmp = [](PII left, PII right) {
            if (left.first == right.first) {
                return left.second > right.second;
            }
            return left.first > right.first;
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp); 

        for (auto elem : freq) {
            pq.push({elem.second, elem.first});
            if (pq.size() > k ) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
