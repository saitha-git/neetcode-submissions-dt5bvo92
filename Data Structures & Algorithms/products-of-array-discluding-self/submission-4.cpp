class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> p1(size,1);
        vector<int> p2(size,1);
        
        for(int i=1; i<size; i++) {
            p1[i] = p1[i-1]*nums[i-1];
        }

       for(int i=size-2; i>=0; i--) {
            p2[i] = p2[i+1]*nums[i+1];
        }

        vector<int> ans(size, 1);
        for(int i=0; i<nums.size(); i++){
            ans[i] = p1[i] * p2[i];
        }

        return ans;
    }
};
