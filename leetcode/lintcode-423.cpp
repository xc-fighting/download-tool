class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string &s) {
        // write your code here
        stack<char> parenthesesStack;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                parenthesesStack.push(s[i]);
            }
            else
            {
                if(parenthesesStack.empty()==true)
                {
                    return false;
                }
                if(s[i] == ')')
                {
                   if(parenthesesStack.top()=='(')
                   {
                       parenthesesStack.pop();
                   }
                   else
                   {
                       return false;
                   }
                }
                else if(s[i] == ']')
                {
                   if(parenthesesStack.top()=='[')
                   {
                       parenthesesStack.pop();
                   }
                   else
                   {
                       return false;
                   }
                }
                else if(s[i] == '}')
                {
                   if(parenthesesStack.top()=='{')
                   {
                       parenthesesStack.pop();
                   }
                   else
                   {
                       return false;
                   }
                }
            }
        }
        if(parenthesesStack.empty()==false )
        {
            return false;
        }
        return true;
    }
};