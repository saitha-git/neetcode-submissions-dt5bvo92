class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ++i)
        {
            if ( (i != nums[i]-1) && (nums[nums[i]-1] == nums[i]) )
            {
                return nums[i];
            }

        }

    }
};
