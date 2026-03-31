/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool compareIntervals(Interval i1, Interval i2)
    {
        if (i1.start == i2.start)
            return i1.end <= i2.end;
        
        return i1.start <= i2.start;    
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> prevEndVec;

        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), compareIntervals);
        prevEndVec.push_back(intervals[0].end);
        for(int i=1; i<intervals.size(); ++i)
        {
            int end   = intervals[i].end;
            int start = intervals[i].start;
            int j;
            for( j=0; j<prevEndVec.size(); ++j)
            {
                if (prevEndVec[j] <= start )
                {
                    prevEndVec[j] = end;
                    break;
                }
            }
            if ( j == prevEndVec.size())
            {
                prevEndVec.push_back(end);
                cout << end << endl;
            }
        }

        return prevEndVec.size();
    }
};


