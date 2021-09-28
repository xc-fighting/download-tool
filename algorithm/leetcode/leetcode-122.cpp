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