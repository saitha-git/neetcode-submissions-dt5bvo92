class Solution {
public:
    bool dfs(int start, vector<int>& nums, int& sum, int& total) {
        if (start >= nums.size()) {
            return false;
        }

        sum += nums[start];
        if (2 * sum == total) {
            return true;
        }
        if (dfs(start + 1, nums, sum, total)) {
            return true;
        }
        sum -= nums[start];
        return dfs(start + 1, nums, sum, total);
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) {
            return false;
        }
        int sum = 0;
        return dfs(0, nums, sum, total);
    }
};
