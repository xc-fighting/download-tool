/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

bool compare(Interval& intr1,Interval& intr2)
{
    if(intr1.start < intr2.start)
    {
        return true;
    }
    else if(intr1.start > intr2.start)
    {
        return false;
    }
    else
    {
        if(intr1.end < intr2.end)
        {
            return true;
        }
        return false;
    }
}

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> totalIntervals;
        for(int i=0;i<schedule.size();i++)
        {
            for(int j=0;j<schedule[i].size();j++)
            {
                totalIntervals.push_back(schedule[i][j]);
            }
        }
        sort(totalIntervals.begin(),totalIntervals.end(),compare);
        vector<vector<int>> templist;
        int start = totalIntervals[0].start;
        int end = totalIntervals[0].end;
        for(int i=1;i<totalIntervals.size();i++)
        {
            if(totalIntervals[i].start <= end)
            {
                end = max(end,totalIntervals[i].end);
            }
            else
            {
                templist.push_back(vector<int>{start,end});
                start = totalIntervals[i].start;
                end = totalIntervals[i].end;
                
            }
        }
        templist.push_back(vector<int>{start,end});
        vector<Interval> result;
        for(int i=1;i<templist.size();i++)
        {
            int lastend = templist[i-1][1];
            int currentstart = templist[i][0];
            if(lastend < currentstart)
            {
                Interval intr(lastend,currentstart);
                result.push_back(intr);
            }
        }
        return result;
        
        
        
    }
};