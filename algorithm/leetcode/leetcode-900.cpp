class RLEIterator {
private:
    deque<pair<int,int>> pairQueue;
public:
    RLEIterator(vector<int>& encoding) {
        for( int index = 0; index < encoding.size(); index += 2 ) {
            int freq = encoding[index];
            int number = encoding[index+1];
            pairQueue.push_back(pair<int,int>(number,freq));
        }
    }
    
    int next(int n) {
        int total = 0;
        int lastElem = -1;
        while( pairQueue.empty() == false ) {
            pair<int,int> topPair = pairQueue.front();
            pairQueue.pop_front();
            if(total + topPair.second <= n) {
                lastElem = topPair.first;
                total = total + topPair.second;
            }
            else {
                int decrease = n - total;
                lastElem = topPair.first;
                topPair.second = topPair.second - decrease;
                pairQueue.push_front(topPair);
                total = n;
            }
            
            if(total == n) {
                break;
            }
        }
        if(total < n) {
            return -1;
        }
        return lastElem;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */