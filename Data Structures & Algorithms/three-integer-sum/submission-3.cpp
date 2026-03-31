class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); ++i)
        {
            if(nums[i] > 0 )
                break;

            if (i>0 && nums[i] == nums[i-1])
                continue;
            
            int j = i+1;
            int k = nums.size() - 1; 
            int sum;

            while (j < k)
            {
                sum = nums[i]+nums[j]+nums[k];
                if (0 == sum)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1])
                        j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
     
        return ans;
    }
};


