class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end   = intervals[0][1];
        merged.push_back({start,end});
        for(int i=1; i<intervals.size(); ++i)
        {
            if (intervals[i][0] > end)
            {

                merged.push_back(intervals[i]);
                start = intervals[i][0];
                end   = intervals[i][1]; 
            }
            else
            {
                start = min(intervals[i][0], start);
                end = max(intervals[i][1], end);
                merged.pop_back();
                merged.push_back({start,end});
            }
        }

        return merged;
    }
};

