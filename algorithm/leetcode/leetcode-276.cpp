class Solution {
public:
    int numWays(int n, int k) {
       vector<int> memo(n+1,-1);
       return getWays(n,k,memo);
    }
    
    int getWays(int n,int k,vector<int>& memo) {
        if(memo[n] != -1) {
            return memo[n];
        }
        if(n==0) {
            return 0;
        }
        if(n==1) {
            return k;
        }
        if(n==2) {
            return k + k*(k-1);
        }
        
        // two consecutive same color
        //for every previous solution we assume its last color is x
        // then for each of them it has k-1 last color which is different from it
        int solution1 = getWays(n-2,k,memo)* (k-1);
        int solution2 = getWays(n-1,k,memo)*(k-1);
        memo[n] = solution1+solution2;
        return solution1+solution2;
        
    }
};