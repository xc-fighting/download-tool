class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curLowest = -1;
        for( int day = 0; day < prices.size(); day++ ) {
             if( curLowest == -1 ) {
                 curLowest = day;
                 continue;
             }
             
             int curPrice = prices[day];
             if( curPrice < prices[curLowest] ) {
                  curLowest = day;
             }
             else {
                 profit = max( profit, curPrice - prices[curLowest] );
             }
        }
        return profit;
    }
};