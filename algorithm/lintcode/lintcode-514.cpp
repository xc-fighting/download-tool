class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if( n == 1 ) {
            return k;
        }
        // write your code here
        vector<int> memo(n+1,0);
        //memo[i] represent number of ways to paint first i fences with k colors
        //for understanding, we can have three color red,yellow,blue
        // so k = 3
        memo[0] = 0;
        memo[1] = k; //only one fence, choose red/yellow/blue 
        /*
           two fence:
           same color solution:
            red red 
            yellow yellow 
            blue blue 
            there is k solution for same color 

            different solution
            first one can choose from   next can choose from 
            red          yellow / blue

            yellow       red/ blue

            blue         red/yellow 
            so it is k*k-1
        */
        memo[2] = k + k*(k-1);
        /*
           base on this analysis
           for first i fences 
           two method:
           keep i-1 and i the same color 
           there are memo[i-2] ways to paint first i-2 fences 
           and suppose each method last color is x, for 
           fences i-1 and i there are k-1 different color than x to 
           paint them the same 
           so it is  memo[i-2]*(k-1);

           make i-1 and i the different color 
           there are memo[i-1] ways to paint first i-1 fences 
           suppose the i-1 fence color y, there are also k-1 different color 
           choose from y for fence i 
           so it is also memo[i-1]*(k-1)
        */
        for( int fence = 3; fence <= n; fence++ ) {
            memo[fence] = memo[fence-1] * (k-1) + memo[fence-2] * (k-1);
        }

        return memo[n];
    }
};