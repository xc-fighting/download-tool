class Solution {
public:
    /**
     * @param str: s string
     * @return: return an integer, denote the number of the palindromic substrings
     */
    int countPalindromicSubstrings(string &str) {
        // write your code here
        int len = str.size();
        vector<vector<int>> memo(len,vector<int>(len,-1));
        for(int i=0;i<len;i++)
        {
            memo[i][i] = 1;
        }
        for(int i=0;i<len-1;i++)
        {
            if(str[i] == str[i+1])
            {
               memo[i][i+1] = 1;
            }
            else
            {
               memo[i][i+1] = 0;
            }
        }

        for(int delta = 2; delta < len; delta++)
        {
            for(int left = 0; left < len; left++ )
            {
                int right = min(len-1, left+delta);
                if(str[left] == str[right])
                {
                    int innerLeft = left + 1;
                    int innerRight = right - 1;
                    if(innerLeft <= innerRight)
                    {
                        if(memo[innerLeft][innerRight] == 1)
                        {
                            memo[left][right] = 1;
                        }
                        else
                        {
                            memo[left][right] = 0;
                        }
                    }
                    else
                    {
                        memo[left][right] = 1;
                    }
                }
                else
                {
                    memo[left][right] = 0;
                }
            }
        }

        int result = 0;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(memo[i][j] == 1)
                {
                    result++;
                }
            }
        }
        return result;

    }
};