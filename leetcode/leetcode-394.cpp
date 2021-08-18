class Solution {
public:
    string decodeString(string s) {
        stack<char> charStack;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
            {
                charStack.push('[');
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                charStack.push(s[i]);
            }
            else if(s[i] >= 'a' && s[i] <= 'z')
            {
                charStack.push(s[i]);
            }
            else
            {
                string decodeStr = "";
                
                while(charStack.empty()==false && charStack.top() != '[')
                {
                    decodeStr = charStack.top() + decodeStr;
                    charStack.pop();
                }
                
                charStack.pop();
                int freq = 0;
                int base = 1;
                while(charStack.empty()==false && charStack.top() >= '0' && charStack.top() <= '9')
                {
                    int digit = charStack.top() - '0';
                    charStack.pop();
                    freq = freq + digit*base;
                    base = base * 10;
                    
                    
                }
                string temp_result = "";
                for(int j = 0; j < freq; j++)
                {
                    temp_result = decodeStr + temp_result;
                }
                for(int k =0; k< temp_result.size(); k++)
                {
                    charStack.push(temp_result[k]);
                }
            }
        }
        string result = "";
        while(charStack.empty()==false)
        {
            result = charStack.top() + result;
            charStack.pop();
        }
        return result;
        
    }
};