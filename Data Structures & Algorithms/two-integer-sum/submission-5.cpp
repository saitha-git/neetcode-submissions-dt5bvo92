class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap; // nums[idx], idx

        int idx;
        for(idx = 0; idx<nums.size(); idx++) {
            int key = target - nums[idx];
            auto it = prevMap.find(key);
            if(!prevMap.empty() &&  it != prevMap.end()) {
                return vector<int>{it->second, idx};
            }
            prevMap[nums[idx]] = idx;
        } 

        return {};
    }
};
