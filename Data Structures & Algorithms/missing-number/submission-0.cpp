class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int sum = 0;
        int i;
        for(i=0; i<n; i++)
        {
            res += nums[i];
            sum += i;
        }

        sum = sum+i;

        return sum-res;

    }
};

