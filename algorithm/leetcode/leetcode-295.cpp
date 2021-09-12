class smallHeap { 
public:
    bool operator()(int& lhs,int& rhs) {
        if(lhs < rhs) {
            return false;
        }
        return true;
    }
};
class maxHeap {
public:
    bool operator()(int& lhs, int& rhs) {
        if( lhs < rhs ) {
            return true;
        }
        return false;
    }
};
class MedianFinder {
private:
    priority_queue<int,vector<int>,smallHeap> minQueue;
    priority_queue<int,vector<int>,maxHeap> maxQueue;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        minQueue = priority_queue<int,vector<int>,smallHeap>();
        maxQueue = priority_queue<int,vector<int>,maxHeap>();
    }
    
    void addNum(int num) {
        //only for first push
        if(maxQueue.empty()==true) {
            maxQueue.push(num);
            return;
        }
        
        if(num > maxQueue.top()) {
            minQueue.push(num);
        }
        else {
            maxQueue.push(num);
        }
        
        //check the size of both and re-balance
        if(maxQueue.size() == minQueue.size()) {
            return;
        }
        else if( maxQueue.size() < minQueue.size() ) {
            //in this case balance to the equal
            while(maxQueue.size() < minQueue.size()) {
                int min = minQueue.top();
                minQueue.pop();
                maxQueue.push(min);
            }
        }
        else {
            while( maxQueue.size() > minQueue.size() + 1 ) {
                int max = maxQueue.top();
                maxQueue.pop();
                minQueue.push(max);
            }
        }
        return;
        
    }
    
    double findMedian() {
        if(maxQueue.size()==minQueue.size()) {
            int max = maxQueue.top();
            int min = minQueue.top();
            double median = (double)( (max + min)*1.0f/2.0 );
            return median;
        }
        return maxQueue.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */