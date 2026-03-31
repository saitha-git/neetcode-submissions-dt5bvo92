class Solution {
public:
    
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int start, vector<int>& subset)
    {
        ans.push_back(subset);
        for(int i=start; i<nums.size(); i++)
        {         
            if (i>start && nums[i-1] == nums[i])
            {
                continue;
            }
            
            subset.push_back(nums[i]);  
            dfs(nums, i+1, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        dfs(nums, 0, subset);
        return ans;
    }
};
