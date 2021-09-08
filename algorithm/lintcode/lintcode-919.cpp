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
//error solution
//example: (19,797) (65,424) (136,897) (165,221) (259,722) (314,807) (351,507) (387,722)
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
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        sort(intervals.begin(),intervals.end(),compare);
        int result = 1;
        
        for(int i=1;i<intervals.size();i++)
        {
           int index = i-1;
           int start = intervals[i].start;
           while(index >= 0 )
           {
               if(start < intervals[index].end)
               {
                   index--;
               }
               else
               {
                   
                   break;
               }
              
           }
           if(index < 0)
           {
               result++;
           }
          
        }
        return result;
    }
};

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
struct Compare
{
public:
   bool operator()(Interval& lhs,Interval& rhs)
   {
      if(lhs.end > rhs.end)
      {
          return true;
      }
      return false;
   }
};
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        sort(intervals.begin(),intervals.end(),compare);
        priority_queue<Interval,vector<Interval>,Compare> pq;
        pq.push(intervals[0]);
        int result = 1;
        for(int i=1;i<intervals.size();i++)
        {
            while(pq.empty()==false && intervals[i].start >= pq.top().end)
            {
                pq.pop();
            }
            pq.push(intervals[i]);
            result = max(result,(int)pq.size());
        }
        return result;
    }
};