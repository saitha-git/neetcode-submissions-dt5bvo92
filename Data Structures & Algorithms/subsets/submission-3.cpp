class Solution {
public:
    vector<vector<int>> ans;
    void recursion(vector<int>& nums, vector<int>& subset, int i){
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        recursion(nums, subset, i+1);
        subset.pop_back();
        recursion(nums, subset, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        recursion(nums, subset, 0);

        return ans;
    }
};
