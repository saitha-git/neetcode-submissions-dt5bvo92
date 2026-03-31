class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> p1(size,1);
        
        for(int i=1; i<size; i++) {
            p1[i] = p1[i-1]*nums[i-1];
        }

        int suffix = 1;
        for(int i=size-2; i>=0; i--){
            suffix = suffix * nums[i+1];
            p1[i] = p1[i] * suffix;
        }

        return p1;
    }
};
