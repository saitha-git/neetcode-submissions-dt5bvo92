class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int newStart = newInterval[0];
        int newEnd   = newInterval[1];
        for (int i=0; i<intervals.size(); ++i)
        {         
                    
            if (newEnd < intervals[i][0])
            {
                merged.push_back({newStart, newEnd});
                copy(intervals.begin()+i, intervals.end(), back_inserter(merged));
                return merged;
            }
            else if (newStart > intervals[i][1])
            {
                merged.push_back(intervals[i]);
            }
            else
            {
                newStart = min(newStart, intervals[i][0]);
                newEnd   = max(newEnd, intervals[i][1]);
                cout << "newStart:" << newStart << " newEnd:" << newEnd<< endl;
            }
 
        }
        merged.push_back({newStart, newEnd});

        return merged;
    }
};

