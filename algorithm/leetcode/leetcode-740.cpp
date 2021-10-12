//this problem is similar idea with house rob
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxValue = -1;
        int minValue = INT_MAX;
        for( int index = 0; index < nums.size(); index++ ) {
             maxValue = max( maxValue, nums[index] );
             minValue = min( minValue, nums[index] );
        }
        
        vector<int> memo(maxValue + 1, 0);
        for( int index = 0; index < nums.size(); index++ ) {
            memo[nums[index]]++;
        }
        
        vector<int> dp(maxValue + 1, 0);
        //dp[i] represents the max number of points you can earn with value up to i
        if( minValue == 1 ) {
            dp[minValue] = memo[1];
        }
        else {
            dp[minValue] = memo[minValue] * minValue;
        }
        int lastValue = dp[minValue];
        for( int value = minValue + 1; value <= maxValue; value++ ) {
            if( memo[value] == 0 ) {
                dp[value] = lastValue;
            }
            dp[value] = value * memo[value] + dp[value-2];
            dp[value] = max(dp[value-1], dp[value]);
            lastValue = dp[value];
        }
        return dp[maxValue];
    }
};