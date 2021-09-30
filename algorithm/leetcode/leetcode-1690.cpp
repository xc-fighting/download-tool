//TLE solution
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int len = stones.size();
        vector<int> presum(len,0);
        presum[0] = stones[0];
        for(int i=1; i<stones.size(); i++) {
            presum[i] = stones[i] + presum[i-1];
        }
        vector<vector<vector<int>>> memo(len,vector<vector<int>>(len,vector<int>(2,-1)));
        return getOptimalScoreDiff(memo,stones,presum,0,len-1,1);
    }
    
    /*
      return: the score diff alice - bob 
      with range [left,right] when player is playing 1 for alice ,0 for bob
    */
    int getOptimalScoreDiff(vector<vector<vector<int>>>& memo,
                            vector<int>& stones, vector<int>& presum, 
                            int left, int right, int player) {
        if( left == right ) {
           /* if(player == 1) {
                return stones[left];
            }
            else {
                return -stones[left];
            } */
            return 0;
        }
        if(memo[left][right][player] != -1) {
            return memo[left][right][player];
        }
        
        if( player == 1 ) {
            
            int takeLeftInstant = presum[right] - presum[left+1] + stones[left+1]; 
            int takeLeft = takeLeftInstant + getOptimalScoreDiff(memo,stones,presum,left+1,right,0);
            
            int takeRightInstant = presum[right-1] - presum[left] + stones[left];
            int takeRight = takeRightInstant + getOptimalScoreDiff(memo,stones,presum,left,right-1,0);
            
            memo[left][right][player] = max(takeLeft,takeRight);
           // cout<<ret<<endl;
            return memo[left][right][player];
        }
        
        else {
            int takeLeftInstant = presum[right] - presum[left+1] + stones[left+1]; 
            int takeLeft = getOptimalScoreDiff(memo,stones,presum,left+1,right,1) - takeLeftInstant;
            
            int takeRightInstant = presum[right-1] - presum[left] + stones[left];
            int takeRight = getOptimalScoreDiff(memo,stones,presum,left,right-1,1) - takeRightInstant;
            
            memo[left][right][player] = min(takeLeft,takeRight);
            return memo[left][right][player];
            
        }
    }
};