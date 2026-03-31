class Solution {
public:
    set<vector<int>> ans;
    
    void recursion(vector<int>& nums, int target, int idx, vector<int>& subset) {
        if(target == 0) {
            ans.insert(subset);
            return;
        }
        
        if(idx == nums.size()){
            return;
        }

        if(nums[idx] <= target){
            //include
            subset.push_back(nums[idx]);
            recursion(nums, target-nums[idx], idx+1, subset);
            //exclude
            subset.pop_back();
            recursion(nums, target, idx+1, subset);
        } else {
            recursion(nums, target, idx+1, subset);
        }


        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<int> subset;
         sort(candidates.begin(), candidates.end());
         recursion(candidates, target, 0, subset);

         return vector<vector<int>>(ans.begin(), ans.end());
    }
};
