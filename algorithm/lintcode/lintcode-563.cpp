class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        int len = nums.size();
        vector<vector<int>> memo(len+1,vector<int>(target+1,0));
        //memo[i][j] means number of ways to reach j with first
        // i items
        // final answer is memo[len][target]
        // formula:
        // memo[i][j] = memo[i-1][j] + memo[i-1][j-nums[i-1]]
        // initialize with:
        // memo[0][j] = 0  memo[i][0] = 1 memo[0][0] = 1
        for(int i=0;i<=len;i++)
        {
            memo[i][0] = 1;
        }
        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=target;j++)
            {
                if(j>=nums[i-1])
                {
                    memo[i][j] += memo[i-1][j-nums[i-1]];
                }
                memo[i][j] += memo[i-1][j];
            }
        }
        return memo[len][target];
    }
};