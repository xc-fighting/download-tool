class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> chStack;
        int index = 0;
        while( index < s.size() ) {
            if( s[index] == '(' ) {
                chStack.push('(');
            }
            else if( s[index] >= 'a' && s[index] <= 'z') {
                chStack.push(s[index]);
            }
            else {
                queue<char> chQueue;
                while( chStack.empty() == false && chStack.top() != '(' ) {
                    chQueue.push( chStack.top() );
                    chStack.pop();
                }
                if( chStack.empty() == false ) {
                    chStack.pop();
                }
                while( chQueue.empty() == false ) {
                    chStack.push(chQueue.front());
                    chQueue.pop();
                }
            }
            index++;
        }
        string result = "";
        while( chStack.empty() == false ) {
            result = chStack.top() + result;
            chStack.pop();
        }
        return result;
    }
};