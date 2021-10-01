//DP method with tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<vector<int>> memo(len+1,vector<int>(amount+1,-1));
        //memo[i][j] represent the minimum number of coins use first i kinds of coin to achieve money i
        // memo[i][j] = 1 + memo[i][j-coins[i-1]] or memo[i-1][j]
        // i == 0 || j == 0 is the base case
        // j == 0 memo[i][j] = 0
        // i == 0 memo[i][j] = INT_MAX
        
        // step 1: initialize the base case
        memo[0][0] = 0;
        for( int i = 1; i <= len ; i++ ) {
            memo[i][0] = 0;
        }
        
        for( int j = 1; j <= amount; j++ ) {
            memo[0][j] = INT_MAX;
        }
        
        // step 2: fill in the tables
        for( int type = 1; type <= len; type++ ) {
            
            for( int money = 1; money <= amount; money++ ) {
                
                int curCoinValue = coins[type-1];
                if( money >= curCoinValue && memo[type][money-curCoinValue] != INT_MAX ) {
                    //try use one of the type
                    memo[type][money] = 1 + memo[type][money-curCoinValue];
                }
                
                int notUseAtAll = memo[type-1][money];
                if( memo[type][money] != -1 ) {
                    memo[type][money] = min(memo[type][money], notUseAtAll);
                }
                else {
                    memo[type][money] = notUseAtAll;
                }
            }
        }
        
        if( memo[len][amount] == INT_MAX ) {
             return -1;
        }
        
        return memo[len][amount];
    }
};

// dfs + memo

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<vector<int>> memo(len+1,vector<int>(amount+1,-1));
        int ret = minNumberCoinFrom(coins, memo, 0, amount);
        if( ret == INT_MAX ) {
            return -1;
        }
        return ret;
    }
    
    // this function return the minimum number of coin needed 
    // to start pick from startIndex of coins  and achieve final money amount
    int minNumberCoinFrom(vector<int>& coins, vector<vector<int>>& memo, 
                           int startIndex, int amount) {
         //base case 1
        if( amount == 0 ) {
            //no need to use any coin
            return 0;
        }
        
        //base case 2
        if( startIndex == coins.size() && amount > 0 ) {
            //no way to achieve
            return INT_MAX;
        }
        
        if( memo[startIndex][amount] != -1 ) {
            //check the memo
            return memo[startIndex][amount];
        }
        
        //method 1: use current coins
        int value = coins[startIndex];
        int maxCount = amount / value;
        
        int result = INT_MAX;
        
        for(int coinUse = 0; coinUse <= maxCount; coinUse++ ) {
            int curSum = coinUse * value;
            
            int candidate = minNumberCoinFrom(coins,memo,startIndex+1,amount-curSum);
            if( candidate != INT_MAX ) {
                result = min( result, coinUse + candidate );
            }
            
        }
        
        memo[startIndex][amount] = result;
        return result;
        
    }
};