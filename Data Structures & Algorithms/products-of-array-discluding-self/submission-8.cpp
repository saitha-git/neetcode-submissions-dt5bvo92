class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> ans(size, 1);

        vector<int> prefix(size, 1);
        for(int i=1; i<size; i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        vector<int> suffix(size, 1);
        for(int i=size-2; i>=0; i--){
            suffix[i] = suffix[i+1]*nums[i+1];
            ans[i] = suffix[i]*prefix[i];
        }

        ans[size-1] = prefix[size-1];

        return ans;
    }
};
