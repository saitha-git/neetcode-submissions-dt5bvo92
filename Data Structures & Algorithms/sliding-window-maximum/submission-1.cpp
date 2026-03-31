class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<vector<int>, vector<vector<int>>> maxHeap;

        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            maxHeap.push({nums[i], i});
            if(i >= k-1)
            {
                while(maxHeap.top()[1] < i-(k-1))
                {
                    maxHeap.pop();
                }
                ans.push_back(maxHeap.top()[0]);
            }
        }

        return ans;
    }
};
