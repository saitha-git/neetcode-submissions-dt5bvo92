class Solution {
public:
    int maxSoFar;
    vector<int> memory;

    int dfs(vector<int>& nums, int index) {
        if( index >= nums.size()) {
            return 0;
        }
        
        if (memory[index] != -1) {
            return memory[index];
        }
        // Rob
        int temp1 = nums[index]+dfs(nums, index+2);
        // Dont Rob
        int temp2 = dfs(nums, index+1);

        return memory[index] = max(temp1, temp2);
    }
    
    int rob(vector<int>& nums) {
        
        memory.resize(nums.size(), -1);
        dfs(nums, 0);
        return memory[0];
    }
};
