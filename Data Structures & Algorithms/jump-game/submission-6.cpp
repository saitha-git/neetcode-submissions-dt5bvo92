class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {
                // If the current index is beyond the maximum reachable point.
                return false;
            }
            maxReach = std::max(maxReach, i + nums[i]);
        }
        return maxReach >= n - 1;
    }
};
