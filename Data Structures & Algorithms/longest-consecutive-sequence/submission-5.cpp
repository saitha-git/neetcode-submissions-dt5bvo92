class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxLen = INT_MIN;
        unordered_set<int> set;

        if (nums.empty())
            return 0;

        for(const auto& num: nums)
        {
            set.insert(num);
        }
        
        for(const auto& num: nums)
        {
            int len = 1;
            if (set.find(num-1) == set.end())
            {
                while (set.find(num+len) != set.end())
                {
                    len++;
                }
            }
            maxLen = max(maxLen,len);            
        }

        return maxLen;
    }
};

