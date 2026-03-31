class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start,vector<int>& nums)
    {
        if(start == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i=start; i<nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            solve(start+1, nums);
            swap(nums[i], nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};
