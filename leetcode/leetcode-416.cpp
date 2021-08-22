class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //if it can divide into two equal subset 
        // the sum of it must divisible by 2
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        if( sum % 2 != 0 )
        {
            return false;
        }
        int target = sum / 2;
        int len = nums.size();
        vector<vector<int>> memo(len+1,vector<int>(target+1,-1));
        //memo[i][j] means whether choose a subset from first i elements, target sum j can achieved
        //-1 means not known, 0 means false, 1 means true
       
        for(int i=0;i<len;i++)
        {
            memo[i][0] = 1;
        }
        for(int i=1;i<=target;i++)
        {
            memo[0][i] = 0;
        }
        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int elem = nums[i-1];
                if(elem > j)
                {
                    memo[i][j] = memo[i-1][j];
                }
                else
                {
                    int choice1 = memo[i-1][j];
                    int choice2 = memo[i-1][j-elem];
                    if(choice1 == 0 && choice2 == 0)
                    {
                        memo[i][j] = 0;
                    }
                    else
                    {
                        memo[i][j] = 1;
                    }
                }
            }
        }
        for(int i=1;i<=len;i++)
        {
            if(memo[i][target]==1)
            {
                return true;
            }
        }
        return false;
        
    }
};