class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;

        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];

            if(hash.find(num) != hash.end()) {
                return vector<int>{hash[num], i};
            }
            hash[target-num] = i;
        }
    }
};
