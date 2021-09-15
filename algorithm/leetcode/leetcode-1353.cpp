bool compare(vector<int>& lhs,vector<int>& rhs) {
    if(lhs[1] < rhs[1]) {
        return true;
    }
    else if(lhs[1] == rhs[1]) {
        if(lhs[0] <= rhs[0]) {
            return true;
        }
        return false;
    }
    else {
        return false;
    }
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int maxDay = -1;
        for(int i=0;i<events.size();i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        vector<int> seen(maxDay+1,0);
        sort(events.begin(),events.end(),compare);
        int result = 0;
        for(int i=0;i<events.size();i++) {
            int startDay = events[i][0];
            int endDay = events[i][1];
            for(int day = startDay;day<=endDay;day++) {
                if(seen[day] == 0) {
                    seen[day] = 1;
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};