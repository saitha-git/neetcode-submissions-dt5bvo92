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
    static bool compareInterval(Interval& i1, Interval& i2)
    {
        if(i1.start == i2.start)
        {
            return i1.end <= i2.end;
        } 
        return i1.start <= i2.start;
    }
    
    bool canAttendMeetings(vector<Interval>& intervals) {
        bool res = true;
        sort(intervals.begin(), intervals.end(), compareInterval);

        for(int i=1; i<intervals.size(); ++i)
        {
            if (intervals[i-1].end <= intervals[i].start)
            {

            }
            else
            {
                res = false;
                return res;
            }
        }

        return res;
    }
};

