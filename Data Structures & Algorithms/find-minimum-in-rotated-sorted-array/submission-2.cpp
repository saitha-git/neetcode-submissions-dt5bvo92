class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;

        while(l<=r)
        {
            int mid = l+(r-l)/2;

            if(nums[l] <= nums[r])
            {
                return nums[l];
            }

            
            if( mid-1>=0 &&  nums[mid-1]>nums[mid]
               && mid+1<n && nums[mid+1]>nums[mid] )
            {
                return nums[mid];
            }
            else if(nums[l] <= nums[mid])
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
    }
};



