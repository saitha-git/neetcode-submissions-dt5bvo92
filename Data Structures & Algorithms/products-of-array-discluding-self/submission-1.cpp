class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);

        int i=0;
        int prod = 1;
        for(auto num : nums)
        {
            ans[i++] = prod;
            prod = prod*num;
        }

        prod = 1;
        for(int i=nums.size()-1; i>=0; i--)
        {
            ans[i] = prod*ans[i];
            prod = prod*nums[i];
        }

        return ans;
    }
};
