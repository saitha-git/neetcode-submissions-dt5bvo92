class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        
        res.push_back(subset);
        for(const auto& num: nums)
        {
            int size = res.size();
            for(int i=0; i<size; i++)
            {
                vector<int> newSubset = res[i];
                newSubset.push_back(num);
                res.push_back(newSubset);
            }
        }

        return res;
    }
};
