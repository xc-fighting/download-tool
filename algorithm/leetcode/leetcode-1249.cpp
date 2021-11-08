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

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> parentheseStack;
        for( int index = 0; index < s.size(); index++ ) {
            if( s[index] != '(' && s[index] != ')' ) {
                 continue;
            }
            if( s[index] == '(' ) {
                parentheseStack.push(index);
                continue;
            }
            
            if( parentheseStack.empty() == true ) {
                 parentheseStack.push(index);
            }
            
            else {
                int topIndex = parentheseStack.top();
                if( s[topIndex] == '(' ) {
                    parentheseStack.pop();
                }
                else {
                    parentheseStack.push(index);
                }
            }
        }
        
        if( parentheseStack.empty() == true ) {
            return s;
        }
        
        string result = "";
        int endIndex = s.size() - 1;
        while( parentheseStack.empty() == false ) {
            int index = parentheseStack.top();
            parentheseStack.pop();
            //get the substring from index+ 1 -> endIndex
            int len = endIndex - index;
            string validComponent = s.substr(index+1, len);
            result = validComponent + result;
           // cout<<result<<endl;
            endIndex = index - 1;
            
        }
        if( endIndex < 0 ) {
            return result;
        }
        result = s.substr(0,endIndex+1) + result;
        return result;
    }
};

class Solution {
public:
    void reverse(string& input) {
        int left = 0;
        int right = input.size()-1;
        while( left < right ) {
            char temp = input[left];
            input[left] = input[right];
            input[right] = temp;
            left++;
            right--;
        }
        return;
    }
    string minRemoveToMakeValid(string s) {
        stringstream ss;
        vector<int> deleteIndices;
        int balance = 0;
        
        for(int index = 0; index < s.size(); index++ ) {
            if( s[index] != '(' && s[index] != ')') {
                ss<<s[index];
                continue;
            }
            
            if( s[index] == '(' ) {
                ss<<"(";
                balance++;
                
            }
            
            else {
                balance--;
                
                if(balance >= 0 ) {
                    ss<<")";
                }
                else {
                    balance++;
                }
            }
            
        }
        string firstRound = ss.str();
      //  cout<<firstRound<<endl;
        if( balance == 0 ) {
            return firstRound;
        }
        ss.str("");
        string result = "";
        balance = 0;
        int index = firstRound.size() - 1;
        while( index >= 0 ) {
            if( firstRound[index] != '(' && firstRound[index] != ')' ) {
                ss<<firstRound[index];
                index--;
                continue;
            }
            if( firstRound[index] == ')' ) {
                 balance--;
                 ss<<firstRound[index];
            }
            else {
                balance++;
                if(balance <= 0 ) {
                    ss<<firstRound[index];
                }
                else{
                    balance--;
                }
            }
            index--;
        }
        result = ss.str();
        reverse(result);
        return result;
    }
};