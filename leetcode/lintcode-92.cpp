class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        int len = A.size();
        vector<vector<int>> memo(len+1,vector<int>(m+1,-1));
        // memo[i][j] means the largest size can reach
        // when choosing from first i items with limit of j
        // memo[i][j] = choose i-1 th item or not 
        for(int i=0;i<=len;i++)
        {
            memo[i][0] = 0;
        }
        for(int i=1;i<=m;i++)
        {
            memo[0][i] = INT_MIN;
        }
        int result = INT_MIN;
        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int size = A[i-1];
                if(j >= size)
                {
                    if(memo[i-1][j-size] != INT_MIN)
                    {
                        memo[i][j] = memo[i-1][j-size] + size;
                    }
                    
                }
                memo[i][j] = max(memo[i][j],memo[i-1][j]);
                //cout<<memo[i][]
                result = max(result,memo[i][j]);
            }
        }
        if(result < 0)
        {
            return -1;
        }
        return result;
    }
};