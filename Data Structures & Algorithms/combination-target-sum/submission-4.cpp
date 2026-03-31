class Solution {
public:
    vector<vector<int>> ret;

    void recursion(vector<int>& nums, int target, int idx, vector<int>& ans) {
        if(idx == nums.size()){
            return;
        }
        if(target == 0) {
            ret.push_back(ans);
            return;
        }
        if(nums[idx]<=target) {
            // include
            ans.push_back(nums[idx]);
            recursion(nums, target-nums[idx], idx, ans);
            //exclude
            ans.pop_back();
            recursion(nums, target, idx+1, ans);
        } else {
            // exclude
            recursion(nums, target, idx+1, ans);
        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ans;
        recursion(nums, target, 0, ans);

        return ret;
    }
};
