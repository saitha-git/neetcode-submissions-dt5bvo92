class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(auto num: nums)
        {
            cout << num << " ";
        }
        cout << endl;

        int i=0;
        int count = 1;
        int ans = 1;

        if ( nums.size() == 0 )
        {
            return 0;
        }

        for(i=0; i<nums.size()-1; ++i)
        {
            if (nums[i+1] - nums[i] == 0)
            {
                // ignore the same elements
            }               
            else if ( (nums[i+1] - nums[i] == 1)
                    || (nums[i+1] - nums[i] == -1)) 
            {
                count++;
                ans = max(count,ans);
            }
            else
            {
                count = 1;
            }
        }

        return ans;
           
    }
};
