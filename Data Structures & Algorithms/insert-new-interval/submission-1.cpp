class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        int i=0;
        while(i<intervals.size() && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        ans.push_back(newInterval);

        for(; i<intervals.size(); i++)
        {
            if (ans.back()[1] < intervals[i][0])
            {
                copy(intervals.begin()+i, intervals.end(), back_inserter(ans));
                break;
            }
            else
            {
                // merge
                auto back = ans.back();
                ans.pop_back();
                ans.push_back({min(back[0],intervals[i][0]),
                               max(back[1],intervals[i][1])});
            }
        }

        return ans;
    }
};
