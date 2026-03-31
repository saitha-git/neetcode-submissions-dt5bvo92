class Solution {
public:
    void dfs(vector<int>& nums, int index, vector<int> subset, vector<vector<int>>& res)
    {
        if (index == nums.size())
        {
            res.push_back(subset);
            return;
        }
        

        dfs(nums,index+1,subset, res);
        vector<int> op2 = subset;
        op2.push_back(nums[index]);
        dfs(nums,index+1, op2, res);
    }
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        dfs(nums, 0, subset, res);
        return res;
    }
};
