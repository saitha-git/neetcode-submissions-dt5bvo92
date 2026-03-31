class Solution {
public:
    
    void subsetSum(vector<int>& nums, int target, vector<int> subset, int index, vector<vector<int>>& res)
    {
        if ( target == 0 || index >= nums.size() )
        {
            if (target == 0)
                res.push_back(subset);
            return;
        }

        vector<int> op1 = subset;
        op1.push_back(nums[index]);
        if ( nums[index] <= target )
            subsetSum(nums, target-nums[index], op1, index, res);
        subsetSum(nums, target, subset, index+1, res);
    }

    
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset = {};
        vector<vector<int>> res;
        
        subsetSum(nums, target, subset, 0, res);
        return res;

    }
};
