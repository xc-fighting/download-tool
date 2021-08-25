class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integer
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        int len = A.size();
        vector<vector<vector<int>>> memo(len+1,vector<vector<int>>(k+1,vector<int>(target+1,-1)));
        for(int i=0;i<=len;i++)
        {
            memo[i][0][0] = 1;
        }
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=target;j++)
            {
                memo[len][i][j] = 0;
            }
        }
        return getWays(A,memo,0,k,target);
    }

    int getWays(vector<int> &A,vector<vector<vector<int>>>& memo,int CurrentIndex,int k,int target)
    {
        
        if(k==0)
        {
            if(target==0)
            {
               return 1;
            }
            else 
            {
                return 0;
            }
        }
        if(CurrentIndex >= A.size())
        {
            return 0;
        }
        if(memo[CurrentIndex][k][target]!=-1)
        {
            return memo[CurrentIndex][k][target];
        }
        int ways = 0;
        int choose = 0;
        int notchoose = 0;
        if(target >= A[CurrentIndex])
        {
            choose = getWays(A,memo,CurrentIndex+1,k-1,target - A[CurrentIndex]);
        }
        notchoose = getWays(A,memo,CurrentIndex+1,k,target);
        memo[CurrentIndex][k][target] = choose + notchoose;
        return choose+notchoose;
    }
};