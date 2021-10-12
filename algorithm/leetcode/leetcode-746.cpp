class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> memo(size, -1);
        int candidate1 = getMinCostFrom(cost, memo, 0);
        int candidate2 = getMinCostFrom(cost, memo, 1);
        return min(candidate1, candidate2);
    }
    
    int getMinCostFrom(vector<int>& cost, vector<int>& memo, int startIndex) {
        if( startIndex >= cost.size() ) {
            return 0;
        }
        if( memo[startIndex] != -1 ) {
            return memo[startIndex];
        }
        int climbOne = cost[startIndex] + getMinCostFrom(cost,memo,startIndex+1);
        int climbTwo = cost[startIndex] + getMinCostFrom(cost,memo,startIndex+2);
        memo[startIndex] = min(climbOne,climbTwo);
        return memo[startIndex];
    }
};