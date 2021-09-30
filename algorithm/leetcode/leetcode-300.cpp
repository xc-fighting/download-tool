class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> memo(len,1);
        //memo[i] means the longest subsequence end at nums[i]
        for( int curIndex = 1; curIndex < len; curIndex++ ) {
             for( int prevIndex = 0; prevIndex < curIndex; prevIndex++ ) {
                  if( nums[curIndex] > nums[prevIndex] ) {
                      memo[curIndex] = max( memo[curIndex], 1 + memo[prevIndex] );
                  }
             }
        }
        
        int result = 1;
        for( int index = 0; index < len; index++ ) {
            result = max( result, memo[index] );
        }
        return result;
    }
};