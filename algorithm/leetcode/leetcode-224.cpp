class Solution {
public:
    int calculate(string s) {
        stack<string> calculateStack;
        int index = 0;
        while( index < s.size() ) {
            
            if( s[index] == ' ' ) {
                index++;
                continue;
            }
            if( s[index] == '(' || s[index] == '+' || s[index] == '-' ) {
                
                string str(1,s[index]);
               // cout<<str<<endl;
                calculateStack.push(str);
                index++;
                continue;
            }
            
            if( s[index] >= '0' && s[index] <= '9' ) {
                int startIndex = index;
                while( index < s.size() && s[index] >= '0' && s[index] <= '9' ) {
                    index++;
                }
                int len = index - startIndex;
                string numStr = s.substr(startIndex, len);
              //  cout<<numStr<<endl;
                calculateStack.push(numStr);
            }
            // when s[index] == ')'
            else {
               int total = 0;
               while( calculateStack.empty() == false && calculateStack.top() != "(" ) {
                   string topStr = calculateStack.top();
                   
                   calculateStack.pop();
                 //  cout<<topStr<<endl;
                   int number = stoi(topStr);
                   if( calculateStack.empty() == false && calculateStack.top() != "(" ) {
                       string sign = calculateStack.top();
                     //  cout<<sign<<endl;
                       calculateStack.pop();
                       if( sign.compare("-") == 0 ) {
                           number = -number;
                       }
                       
                       
                   }
                   total += number;
                   
               }
              // cout<<"the total is:"<<total<<endl;
               if( calculateStack.empty() == false && calculateStack.top().compare("(") == 0 ) {
                   calculateStack.pop();
               }
               
               calculateStack.push( to_string(total) );
               index++;
            }
            
        }
        
        int result = 0;
        while( calculateStack.empty() == false ) {
            
            string top = calculateStack.top();
           // cout<<"top:"<<top<<endl;
            int currentNumber = stoi(top);
          //  cout<<currentNumber<<endl;
            calculateStack.pop();
            if( calculateStack.empty() == false ) {
                string sign = calculateStack.top();
                calculateStack.pop();
                if( sign.compare("-") == 0) {
                    currentNumber = -currentNumber;
                }
            }
            result = result + currentNumber;
        }
        return result;
    }
};