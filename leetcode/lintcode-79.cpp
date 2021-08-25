class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        if(A.size()==0 && B.size()==0)
        {
            return 0;
        }

        // write your code here
        int lenA = A.size();
        int lenB = B.size();

        vector<vector<int>> memo(lenA+1, vector<int>(lenB+1,0));
        if(A[0]==B[0])
        {
            memo[0][0] = 0;
        }
        //memo[i][j] represent the length of longest common substring
        // between A and B end with i and j
        // memo[i][j] if(A[i-1] == B[j-1]) 1+memo[i-1][j-1]
        // memo[i][j] = 0
        int longestCommon = 0;
        for(int i=1;i<=lenA;i++)
        {
            for(int j=1;j<=lenB;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    memo[i][j] = 1 + memo[i-1][j-1];
                }
                else
                {
                    memo[i][j] = 0;
                }
                
            }
        }
        for(int i=1;i<=lenA;i++)
        {
            for(int j=1;j<=lenB;j++)
            {
                longestCommon = max(longestCommon,memo[i][j]);
            }
        }
        return longestCommon;
    }
};