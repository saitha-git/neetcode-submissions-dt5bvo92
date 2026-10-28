class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevMap; // nums[idx], idx

        int idx;
        for(idx = 0; idx<nums.size(); idx++) {
            int key = target - nums[idx];
            if(!prevMap.empty() && prevMap.find(key) != prevMap.end()) {
                return vector<int>{prevMap[key], idx};
            }
            prevMap[nums[idx]] = idx;
        } 

        return {};
    }
};
