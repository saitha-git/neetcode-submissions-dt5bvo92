class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> p1;
        vector<int> p2;
        int size = nums.size();
        
        p1.resize(size);
        p2.resize(size);

        
        p1[0] = 1;
        for(int i=1; i<size; i++) {
            p1[i] = p1[i-1]*nums[i-1];
        }

        p2[size-1] = 1;
        for(int i=size-2; i>=0; i--) {
            p2[i] = p2[i+1]*nums[i+1];
        }

        vector<int> ans;
        ans.resize(nums.size());
        for(int i=0; i<nums.size(); i++){
            ans[i] = p1[i] * p2[i];
        }

        return ans;
    }
};
