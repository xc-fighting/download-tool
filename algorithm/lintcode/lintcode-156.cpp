/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
bool compare(Interval& lhs,Interval& rhs)
{
    if(lhs.start < rhs.start)
    {
        return true;
    }
    return false;
}
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        if(intervals.size()<=1)
        {
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),compare);
        int start = intervals[0].start;
        int end = intervals[0].end;
        vector<Interval> result;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start <= end )
            {
                end = max(intervals[i].end,end);
            }
            else
            {
                Interval newIntr(start,end);
                result.push_back(newIntr);
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        result.push_back(Interval(start,end));
        return result;
    }
};