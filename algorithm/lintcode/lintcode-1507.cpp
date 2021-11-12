struct comp {
public:
    bool operator()(pair<int,int>& lhs, pair<int,int>& rhs) {
        if( lhs.second > rhs.second ) {
            return true;
        }
        return false;
    }

};
class Heap {
public:

    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    unordered_set<int> deleteSet;

    Heap() {

    }

    void push(pair<int,int> elem) {
       // cout<<"push data:"<<elem.first<<","<<elem.second<<endl;
        pq.push(elem);
    } 

    void pop() {
       while( pq.empty() == false && deleteSet.find(pq.top().first) != deleteSet.end() ) {
            deleteSet.erase(pq.top().first);
            pq.pop();
            
        }
        if(pq.empty() == true ) {
            return;
        }
        pq.pop();
        return;
    }

    pair<int,int> top() {
        while( pq.empty() == false && deleteSet.find(pq.top().first) != deleteSet.end() ) {
            cout<<"get here=============="<<endl;
            deleteSet.erase(pq.top().first);
            pq.pop();
            
        }
        if( pq.empty() == true ) {
            return pair<int,int>(-1,-1);
        }
        return pq.top();
    }

    void Delete(int index) {
         cout<<"insert index"<<index<<endl;
         deleteSet.insert(index);
    }

    int size() {
        int pqSize = pq.size();
        int lazyDeleteSize = deleteSet.size();
        return pqSize - lazyDeleteSize;
    }
};
class Solution {
public:
    /**
     * @param A: the array
     * @param K: sum
     * @return: the length
     */
    

    
    bool check(vector<int>& A, int k, int mid) {
        int len = A.size();
        vector<int> presum(len,0);
        presum[0] = A[0];
        for( int index = 1; index < len; index++ ) {
            presum[index] = A[index] + presum[index-1];
        }
        //cout<<presum[len-1]<<endl;
        Heap minHeap;
        int left = 0;
        for( int index = 0; index < A.size(); index++ ) {
            cout<<"the index:"<<index<<endl;
            if( index < mid ) {
                minHeap.push(pair<int,int>(index,presum[index]));
                if( presum[index] >= k ) {
                    return true;
                }
            }
            else {
                //when it is larger or equal to mid
                pair<int,int> topPair = minHeap.top();
                cout<<"the top pair:"<<topPair.first<<"->"<<topPair.second<<endl;
                int prevIndex = topPair.first;
                int sum = presum[index] - topPair.second;
                int len = index - prevIndex;
                if( len <= mid && sum >= k ) {
                    return true;
                }
                
                minHeap.Delete(left);
                left++;
                minHeap.push(pair<int,int>(index,presum[index]));
            }
        }
        return false;

        
    }
    int shortestSubarray(vector<int> &A, int K) {
        // Write your code here.
        //sliding window will not work since  it has both positive and negative value 
        int minLen = 1;
        int maxLen = A.size();
        while( minLen + 1 < maxLen ) {
            cout<<minLen<<","<<maxLen<<endl;
            int midLen = minLen + ( maxLen - minLen ) / 2;
            cout<<"check len with:"<<midLen<<endl;
            if( check(A,K,midLen) == true ) {
                //try to shorten the length
                maxLen = midLen;
            }
            else {
                minLen = midLen;
            }
        }
        //make a check here
        if( check(A,K,minLen) ) {
            return minLen;
        }
        if( check(A,K,maxLen) ) {
            return maxLen;
        }
        return -1;
    }
};