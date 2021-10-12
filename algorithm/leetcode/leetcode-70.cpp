class Solution {
public:
    int climbStairs(int n) {
        if( n == 1 ) {
            return 1;
        }
        if( n == 2 ) {
            return 2;
        }
        vector<int> memo(n+1, -1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 2;
        for( int step = 3; step <= n; step++ ) {
            memo[step] = memo[step-1] + memo[step-2];
        }
        return memo[n];
    }
};