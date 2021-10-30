class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tempbuffer(nums);
        sort(tempbuffer.begin(),tempbuffer.end());
        int minIndex = -1;
        int maxIndex = -1;
        for( int index = 0; index < tempbuffer.size(); index++ ) {
            if( tempbuffer[index] != nums[index] ) {
                if(minIndex == -1) {
                    minIndex = index;
                }
                maxIndex = index;
            }
        }
        if( minIndex == -1 ) {
            return 0;
        }
        return maxIndex - minIndex + 1;
    }
}

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minOutOfOrder = INT_MAX;
        int maxOutOfOrder = INT_MIN;
        for( int index = 0; index < nums.size() - 1; index++ ) {
            if( nums[index] > nums[index+1] ) {
                minOutOfOrder = min(minOutOfOrder, nums[index+1]);
                maxOutOfOrder = max(maxOutOfOrder, nums[index]);
            }
        }
        if( minOutOfOrder == INT_MAX ) {
            return 0;
        }
        int smallerThanMinCount = 0;
        int largerThanMaxCount = 0;
        for( int index = 0; index < nums.size(); index++ ) {
            if( nums[index] < minOutOfOrder ) {
                smallerThanMinCount++;
            }
        }
        for( int index = 0; index < nums.size(); index++ ) {
            if( nums[index] > maxOutOfOrder ) {
                largerThanMaxCount++;
            }
        }
        int smallerIndex = smallerThanMinCount;
        while( smallerIndex < nums.size() && nums[smallerIndex] == minOutOfOrder ) {
            smallerIndex++;
        }
        int largerIndex = nums.size() - 1 - largerThanMaxCount;
        while( largerIndex >= 0 && nums[largerIndex] == maxOutOfOrder ) {
            largerIndex--;
        }
        
        return largerIndex - smallerIndex + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minIndex = -1;
        int maxIndex = -1;
        for( int pos = 0; pos < nums.size() - 1; pos++ ) {
            for( int next = pos + 1; next < nums.size(); next++ ) {
                if( nums[pos] > nums[next] ) {
                    if( minIndex == -1 ) {
                        minIndex = pos;
                      //  cout<<minIndex<<endl;
                    }
                    maxIndex = max(maxIndex,next);
                } 
            }
        }
        if(minIndex == -1) {
            return 0;
        }
        return maxIndex - minIndex + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       stack<int> indexStack;
       int minIndex = INT_MAX;
       int maxIndex = INT_MIN;
       for(int index = 0; index < nums.size(); index++ ) {
           if( indexStack.empty() == true ) {
               indexStack.push(index);
               continue;
           }
           if( nums[index] > nums[indexStack.top()] ) {
                indexStack.push(index);
           } 
           else {
               stack<int> tempbuffer;
               while( indexStack.empty() == false 
                     && nums[index] < nums[indexStack.top()]) {
                   minIndex = min(indexStack.top(),minIndex);
                   maxIndex = index;
                   tempbuffer.push(indexStack.top());
                   indexStack.pop();
               }
               if(indexStack.empty()==true) {
                   minIndex = 0;
               }
               while(tempbuffer.empty()==false) {
                   indexStack.push(tempbuffer.top());
                   tempbuffer.pop();
               }
           }
       }
       if(minIndex == INT_MAX) {
           return 0;
       } 
       return maxIndex - minIndex + 1;
    }
};