class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        //same problem:
        int len = A.size();
        vector<vector<int>> memo(len+1,vector<int>(m+1,-1));
        //memo[i][j] means the max value can be reached
        //when choose from first i items with backpack limit of j
        for(int i=1;i<=m;i++)
        {
            memo[0][i] = INT_MIN;
        }
        for(int j=0;j<=len;j++)
        {
            memo[j][0] = 0;
        }
        int maxVal = INT_MIN;
        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int itemValue = V[i-1];
                int itemSize = A[i-1];
                if(j >= itemSize)
                {
                    if(memo[i-1][j-itemSize] != INT_MIN)
                    {
                        memo[i][j] = itemValue + memo[i-1][j-itemSize];
                    }
                }
                memo[i][j] = max(memo[i][j],memo[i-1][j]);
                maxVal = max(memo[i][j],maxVal);
            }
        }
        if(maxVal != INT_MIN)
        {
            return maxVal;
        }
        return -1;
    }
};