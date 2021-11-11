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
bool compare(Interval& lhs, Interval& rhs) {
    if( lhs.start < rhs.start ) {
        return true;
    }
    return false;
}
struct comp {
public:
   bool operator()(Interval& lhs, Interval& rhs) {
       if( lhs.end < rhs.end ) {
           return false;
       }
       return true;
   }
};
class Solution {
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        sort(airplanes.begin(), airplanes.end(), compare);
        priority_queue<Interval,vector<Interval>,comp> pq;
        int maxCount = 0;
        for( int index = 0; index < airplanes.size(); index++ ) {
            if( pq.empty() == true ) {
                pq.push(airplanes[index]);
            }
            else {
                int curStart = airplanes[index].start;
                while( pq.empty() == false && curStart >= pq.top().end ) {
                    pq.pop();
                }
                pq.push(airplanes[index]);
            }
            int size = pq.size();
            maxCount = max(maxCount,size);
        }
        return maxCount;
    }
};