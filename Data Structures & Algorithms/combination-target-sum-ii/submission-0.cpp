class Solution {
public:
    vector<vector<int>> res;

    void solve(int start, vector<int>& candidates, int target, vector<int>& ans, int& sum)
    {
        
        if (target == sum)
        {
            res.push_back(ans);
            return;
        }

        for(int i=start; i<candidates.size(); i++)
        {
            if(i>start && candidates[i] == candidates[i-1] )
            {
                continue;
            }
            
            if (candidates[i] <= target - sum )
            {
                
                sum += candidates[i];
                ans.push_back(candidates[i]);
                cout << "start:" << start << "sum:" << sum << endl;
                solve(i+1, candidates, target, ans, sum);
                ans.pop_back();
                sum -= candidates[i];
                cout << "end:start:" << start << "sum:" << sum << endl;
            }
            else
            {

            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        int sum = 0;
        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, ans, sum);

        return res;
    }
};
