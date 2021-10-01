class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        //memo[i] save the size of longest divisible set end with nums[i]
        vector<int> memo(len,1);
        //parent[i] save the previous end of longest divisible set end with i
        vector<int> parent(len,-1);
        for(int i = 0; i < len; i++) {
            parent[i] = i;
        }
        
        for(int index = 1; index < len; index++ ) {
            int curVal = nums[index];
            for(int preIndex = 0; preIndex < index; preIndex++) {
                 if( curVal % nums[preIndex] == 0 ) {
                      int candidate = 1 + memo[preIndex];
                      if( candidate > memo[index] ) {
                           memo[index] = candidate;
                           parent[index] = preIndex;
                      }
                 }
            }
        }
        
        int largestIndex = 0;
        for(int index = 1; index < len; index++ ) {
            if( memo[index] > memo[largestIndex]) {
                largestIndex = index;
            }
        }
        
        //use the largest index to back trace the path
        vector<int> result;
        int curIndex = largestIndex;
        while( parent[curIndex] != curIndex ) {
            result.push_back(nums[curIndex]);
            curIndex = parent[curIndex];
        }
        result.push_back(nums[curIndex]);
        return result;
     }
};


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        unordered_map<int,vector<int>> memo;
        for(int i=0;i<len;i++) {
            getLongestStartWith(nums,memo,i);
        }
        
        int longest = 0;
        int longestIndex = -1;
        for(pair<int,vector<int>> elem:memo) {
            int key = elem.first;
            if(elem.second.size() > longest) {
                longest = elem.second.size();
                longestIndex = key;
            }
        }
        return memo[longestIndex];
     }
    
     vector<int> getLongestStartWith(vector<int>& nums,
                                     unordered_map<int,vector<int>>& memo, 
                                     int index) {
          if( index == nums.size() ) {
              return vector<int>();
          } 
          if(memo.find(index) != memo.end()) {
              return memo[index];
          }
          int curValue = nums[index];
          int curLen = 1;
          vector<int> result;
          result.push_back(curValue);
          for(int next = index + 1; next < nums.size(); next++ ) {
              if( nums[next] % curValue == 0 ) {
                   vector<int> nextList = getLongestStartWith(nums,memo,next);
                   if( nextList.size() + 1 > curLen ) {
                        curLen = nextList.size() + 1;
                        result.clear();
                        result.push_back(curValue);
                        for( int i = 0; i< nextList.size(); i++ ) {
                            result.push_back(nextList[i]);
                        }
                   }
              }
              else {
                  continue;
              }
          }
          memo[index] = vector<int>(result);
          return result;
     }
     
};
