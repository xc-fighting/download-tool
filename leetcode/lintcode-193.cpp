class Solution {
public:
    /**
     * @param s: a string
     * @return: return a integer
     */
    int longestValidParentheses(string &s) {
        stack<int> IndexStack;
        int result = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                IndexStack.push(i);
            }
            else
            {
                //current element is ')'
                if(IndexStack.empty()==false)
                {
                    int idx = IndexStack.top();
                    if(s[idx] == '(')
                    {
                        IndexStack.pop();
                        if(IndexStack.empty()==true)
                        {
                            result = max(result,i+1);
                        }
                        else
                        {
                            result = max(result,i-IndexStack.top());
                        }
                    }
                    else
                    {
                        IndexStack.push(i);
                    }
                }
                else
                {
                    IndexStack.push(i);
                }
            }
        }
        return result;
    }
};