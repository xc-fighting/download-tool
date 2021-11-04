class Solution {
public:
    vector<string> addOperators(string num, int target) {
         vector<string> expressions;
         addOperators(expressions,num,0,"",0,0,target);
         return expressions;
    }
    
    
    
    
    void addOperators(vector<string>& expressions, string num, 
                      int start, string curExpression, 
                      long curSum, long prevNum, int target ) {
        
        if( start == num.size() && curSum == target ) {
             //border case
             expressions.push_back(curExpression);
             return;
        }
        
        for( int index = start; index < num.size(); index++ ) {
            
            if( index != start  && num[start] == '0' ) {
                 // leading 0 case
                 break;
            }
            string sub = num.substr(start, (index-start+1) );
            long value = stol(sub);
            
            if( start == 0 ) {
                addOperators( expressions, num, index+1, curExpression + sub, curSum + value, value, target );
            }
            else {
                
                addOperators( expressions, num, index+1, curExpression + "+" + sub, curSum + value, value, target );
                
                addOperators( expressions, num, index+1, curExpression + "-" + sub, curSum - value, -value, target );
                
                long remain = curSum - prevNum;
                long newfactor = (long)value * prevNum;
                
                addOperators( expressions, num, index+1, curExpression + "*" + sub, remain + newfactor, newfactor,target );
            }
        }
        return;
    }
    
    
};