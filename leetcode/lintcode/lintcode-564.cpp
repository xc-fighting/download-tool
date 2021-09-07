class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        // write your code here
        vector<int> memo(target+1,0);
        //memo[i] means ways to make target i use all candidate value
        memo[0] = 1;
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                int candidate = nums[j];
                if(i>=candidate)
                {
                    memo[i] += memo[i-candidate];
                }
            }
        }
        return memo[target];
    }
};