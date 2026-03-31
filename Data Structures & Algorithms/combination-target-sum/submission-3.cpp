class Solution {
public:
    vector<vector<int>> res;

    void _combinationSum(vector<int>& nums, int target, int index, vector<int>& subset)
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
            subset.push_back(nums[index]);
            _combinationSum(nums, target-nums[index], index, subset);
            subset.pop_back();
        }
        
        _combinationSum(nums, target, index+1, subset);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        _combinationSum(nums, target, 0, subset);
        return res;
    }
};
