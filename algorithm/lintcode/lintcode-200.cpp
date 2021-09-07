class Solution {
public:
    /**
     * @param s: input string
     * @return: a string as the longest palindromic substring
     */
    string longestPalindrome(string &s) {
      // write your code here
        int len = s.size();
        vector<vector<int>> memo(len,vector<int>(len,-1));
        int left = -1;
        int right = -1;
        int result = 1;
        for(int i=0;i<len;i++)
        {
            memo[i][i] = 1;
            if(i+1 < len)
            {
                if(s[i]==s[i+1])
                {
                    memo[i][i+1] = 1;
                    left = i;
                    right = i+1;
                    result = 2;
                    
                }
                else
                {
                    memo[i][i+1] = 0;
                }
            }
            
        }

        
        
        for(int delta=2;delta<=len-1;delta++)
        {
            for(int i=0;i<len;i++)
            {
                
              //  cout<<"loop"<<endl;
                int l = i;
                int r = min(l + delta,len-1);
              //  cout<<l<<" "<<r<<endl;
                if(l==r)
                {
                    continue;
                }
             //   cout<<l<<" "<<r<<endl;
                if(s[l]==s[r])
                {
                    if(memo[l+1][r-1]==1)
                    {
                     //   cout<<"find"<<endl;
                        memo[l][r] = 1;
                        if(r-l+1 > result)
                        {
                            left = l;
                            right = r;
                            result = r-l+1;
                        }
                        
                    }
                    else
                    {
                        memo[l][r] = 0;
                    }
                    
                }
                else
                {
                    memo[l][r] = 0;
                }
            }
        }
        if(left==right)
        {
            return s.substr(0,1);
        }
        //return "";
        return s.substr(left,right-left+1);
        //return result;

    }
};