struct state {
public:
    int pos;
    int speed;
    float time;
    int target;
    state(int pos,int speed,int target) {
        this->pos = pos;
        this->speed = speed;
        int distance = target - pos;
        time = (float) (distance * 1.0f / speed);
    }
};

bool compare(state& lhs, state& rhs) {
    if(lhs.pos < rhs.pos) {
        return true;
    }
    return false;
}
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int len = position.size();
        vector<state> stateList;
        for(int index = 0; index < len; index++ ) {
            state cur(position[index], speed[index], target);
            stateList.push_back(cur);
        }
        
        sort(stateList.begin(), stateList.end(), compare);
        
        int lastIndex = stateList.size() - 1;
        int curFleets = 0;
        while( lastIndex >= 0 ) {
            int prevIndex = lastIndex - 1;
            while(prevIndex >= 0 
                  && stateList[lastIndex].time >= stateList[prevIndex].time) {
                prevIndex--;
            }
            curFleets++;
            
            lastIndex = prevIndex;
            
        }
        return curFleets;
    }
};