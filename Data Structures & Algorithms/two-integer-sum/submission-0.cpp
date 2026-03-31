class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        vector<int> ans;

        for(auto idx=0; idx<nums.size(); ++idx)
        {
            auto rem = target-nums[idx];
            if(hashmap.find(rem)!=hashmap.end())
            {
                ans.push_back(hashmap[rem]);
                ans.push_back(idx);
                break;
            }
            else
            {
                hashmap[nums[idx]] = idx;
            }
        }

        return ans;
    }
};
