//TLE solution
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int len = nums.size();
        int m = multipliers.size();
        vector<vector<vector<int>>> memo(len, vector<vector<int>>(len,vector<int>(m+1,INT_MIN)));
        return maxScore(memo,nums,multipliers,0,nums.size()-1,1,multipliers.size());
    }
    
    int maxScore(vector<vector<vector<int>>>& memo, vector<int>& nums, 
                 vector<int>& multipliers, 
                 int left, int right, 
                 int curOp, int m) {
        if( curOp > m ) {
            return 0;
        }
        
        if(memo[left][right][curOp] != INT_MIN ) {
            return memo[left][right][curOp];
        }
        int leftVal = nums[left] * multipliers[curOp-1];
        int rightVal = nums[right] * multipliers[curOp-1];
        int leftChild = maxScore(memo,nums,multipliers,left+1,right,curOp+1,m);
        int rightChild = maxScore(memo,nums,multipliers,left,right-1,curOp+1,m);
        memo[left][right][curOp] = max(leftVal+leftChild,rightVal+rightChild);
        return memo[left][right][curOp];
    }
};