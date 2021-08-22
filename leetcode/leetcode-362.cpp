class HitCounter {
private:
    queue<int> timequeue;
public:
    /** Initialize your data structure here. */
    HitCounter():timequeue(queue<int>()) {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        timequeue.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int boundaryTime = timestamp - 300;
        while(timequeue.empty()==false)
        {
            if(timequeue.front() <= boundaryTime)
            {
                timequeue.pop();
            }
            else
            {
                break;
            }
        }
        return timequeue.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */