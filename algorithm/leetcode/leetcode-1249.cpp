class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<int> indexStack;
       for( int index = 0; index < s.size(); index++ ) {
           if( s[index] == '(' ) {
               indexStack.push(index);
           }
           else if( s[index] == ')' ) {
               if( indexStack.empty() == true ) {
                   indexStack.push(index);
                    continue;
               }
               int topIndex = indexStack.top();
               if( s[topIndex] == '(' ) {
                   indexStack.pop();
               }
               else {
                   indexStack.push(index);
               }
           }
       }
       if( indexStack.empty() == true ) {
           return s;
       }
       string result= "";
       int start = -1;
       int end = s.size() -1;
       while( indexStack.empty() == false ) {
           int removeIndex = indexStack.top();
           indexStack.pop();
         //  cout<<removeIndex<<endl;
           start = removeIndex + 1;
           string component = s.substr(start,end-start+1);
           result = component + result;
           end = removeIndex - 1;
       }
       if( end >= 0 ) {
           result = s.substr(0,end+1) + result;
       }
       return result;
    }
};