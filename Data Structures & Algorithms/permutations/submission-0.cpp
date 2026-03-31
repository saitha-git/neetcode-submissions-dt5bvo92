class Solution {
public:
    vector<int>         permutation;
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0)
        {
            res.push_back(permutation);
            return res;
        }

        for(int i=0; i<nums.size(); i++)
        {
            vector<int> remainingNums;
            for(int j=0; j<nums.size(); j++)
            {
                if ( i != j)
                    remainingNums.push_back(nums[j]);
            }
            permutation.push_back(nums[i]);
            permute(remainingNums);
            permutation.pop_back();
        }
        
        return res;
    }
};

