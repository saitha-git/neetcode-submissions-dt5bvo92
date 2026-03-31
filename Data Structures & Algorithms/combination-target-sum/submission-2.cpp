class Solution {
public:
    vector<vector<int>> res;

    void _combinationSum(vector<int>& nums, int target, int index, vector<int> subset)
    {
        if ( index == nums.size() || target == 0)
        {
            if (0 == target)
            {
                res.push_back(subset);
            }
            return;
        }
        
        if (nums[index] <= target)
        {
            vector<int> newSubset = subset;
            newSubset.push_back(nums[index]);
            _combinationSum(nums, target-nums[index], index, newSubset);
        }
        
        _combinationSum(nums, target, index+1, subset);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        _combinationSum(nums, target, 0, {});
        return res;
    }
};
