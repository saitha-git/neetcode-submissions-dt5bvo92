class Solution {
public:
    int count;
    void dfs(vector<int>& nums, int i, int sum, int target) {

        if (i == nums.size() ) {
            if(sum == target) {
                count++;
            }
            return;
        }
        
        dfs(nums, i+1, sum+nums[i], target);
        dfs(nums, i+1, sum-nums[i], target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        count = 0;
        dfs(nums, 0, 0, target);
        return count;
    }
};
