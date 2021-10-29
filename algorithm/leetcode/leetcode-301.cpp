class Solution {
public:
    bool isValid( string s ) {
      //   cout<<s<<endl;
         stack<char> chStack;
         for( int index = 0; index < s.size(); index++ ) {
             if( s[index] != '(' && s[index] != ')' ) {
                 continue;
             }
             if( s[index] == '(' ) {
                 chStack.push('(');
             }
             else {
                 if( chStack.empty() == true ) {
                     return false;
                 }
                 char top = chStack.top();
                 if( top != '(' ) {
                     return false;
                 }
                 chStack.pop();
             }
         }
         if( chStack.empty() == false ) {
              return false;
         }
        // cout<<"is valid"<<endl;
         return true;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if( isValid(s) == true ) {
             result.push_back(s);
             return result;
        }
        queue<string> stateQueue;
        unordered_set<string> seen;
        stateQueue.push(s);
        seen.insert(s);
        int step = 0;
        bool find = false;
        while( stateQueue.empty() == false ) {
            int size = stateQueue.size();
            
            for( int i = 0; i < size; i++ ) {
                 string frontState = stateQueue.front();
                 stateQueue.pop();
                 if( isValid(frontState) == true ) {
                     find = true;
                     result.push_back(frontState);
                 }
                 else {
                     for( int index = 0; index < frontState.size(); index++ ) {
                         if( frontState[index] == '(' || frontState[index] == ')' ) {
                             string firstPart = frontState.substr(0,index);
                             
                             string secondPart = frontState.substr(index+1);
                             string newPart = firstPart + secondPart;
                             if(seen.find(newPart) == seen.end()) {
                                 seen.insert(newPart);
                                 stateQueue.push(newPart);
                             }
                         }
                     }
                 }
            }
            if( find == true ) {
                break;
            }
            step++;
        }
        if( find == true ) {
            return result;
        }
        result.push_back("");
        return result;
    }
};
