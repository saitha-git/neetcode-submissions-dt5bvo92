class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result (nums.size(),1);
        vector<int> prefix (nums.size(),1);
        vector<int> suffix (nums.size(),1);
        int temp_pre = 1;
        int temp_suff = 1;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            temp_pre*=nums[i];
            temp_suff*=nums[n-i-1];
            prefix[i]*=temp_pre;
            suffix[n-i-1]*=temp_suff;
        }
        for(int i = 0;i<n;i++){
            if(i==0){
                result[i]=suffix[i+1];
            }
            else if(i==n-1){
                result[i]=prefix[n-2];
            }
            else{
                result[i]=prefix[i-1]*suffix[i+1];
            }
        }
        return result;
    }
};
