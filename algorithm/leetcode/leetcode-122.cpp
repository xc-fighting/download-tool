//tle 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector<int> memo(days, -1);
        return getMaxProfitRecursive(memo,prices,0);
    }
    
    // return the max profit can get start buying from day 
    int getMaxProfitRecursive(vector<int>& memo,vector<int>& prices, int day) {
        if( day == prices.size() ) {
            return 0;
        }
        if( memo[day] != -1 ) {
            return memo[day];
        }
        int profit = 0;
        for( int buyDay = day; buyDay < prices.size(); buyDay++ ) {
            int buyPrice = prices[buyDay];
            // choose a sell day where the price is larger or equal to
            // current buy price
            for( int sellDay = buyDay + 1; sellDay < prices.size(); sellDay++ ) {
                 if( prices[sellDay] >= buyPrice ) {
                      int immediateProfit = prices[sellDay] - buyPrice;
                      int candidateProfit = immediateProfit 
                                         + getMaxProfitRecursive( memo,prices, sellDay+1 );
                      profit = max(profit, candidateProfit);
                      
                 }
            }
            
        }
        memo[day] = profit;
        return profit;
    }
};


//tle solution 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> memo(len, 0);
        //memo[i] means max profit can get when sell at i
        for(int day = 1; day < len; day++) {
            int curPrice = prices[day];
            for(int buy = 0; buy < day; buy++) {
                if(curPrice > prices[buy]) {
                    int curProfit = curPrice - prices[buy];
                    memo[day] = max(memo[day], curProfit);
                    for(int old = 0; old < buy; old++) {
                        memo[day] = max(memo[day], curProfit + memo[old]);
                    }
                }
            }
        }
        
        int res = 0;
        for(int day = 0; day < len; day++) {
            res = max(res, memo[day]);
        }
        return res;
    }
};


