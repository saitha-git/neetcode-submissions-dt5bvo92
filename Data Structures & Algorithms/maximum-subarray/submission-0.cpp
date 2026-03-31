class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = INT_MIN;
        int sum = 0; 

        for(const auto& num : nums)
        {
            sum += num;
            maxSoFar = max(maxSoFar, sum);
            if(sum < 0)
            {
                sum = 0;
            }
            
        }

        return maxSoFar;
    }
};
