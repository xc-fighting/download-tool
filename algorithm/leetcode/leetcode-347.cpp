class comp {
public:
    
    bool operator()( pair<int,int>& lhs, pair<int,int>& rhs ) {
        
        if( lhs.second < rhs.second ) {
            
             return false;
        }
        
        return true;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, comp > pq;
        
        unordered_map<int,int> numFreq;
        
        for( int index = 0; index < nums.size(); index++ ) {
              if( numFreq.find(nums[index]) == numFreq.end() ) {
                   numFreq[nums[index]] = 0;
              }
              
              numFreq[nums[index]]++;
        }
        
        for( pair<int,int> entry: numFreq ) {
            
            pq.push(entry);
            
            if( pq.size() > k ) {
                pq.pop();
            }
        }
        
        vector<int> result(k, -1);
        int index = k - 1;
        while( pq.empty() == false ) {
            
            result[index] = pq.top().first;
            pq.pop();
            
            index--;
        }
        
        int left = 0;
        int right = result.size() - 1;
        
        while( left < right ) {
            
            int temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            left++;
            right--;
        }
        
        return result;
    }
};