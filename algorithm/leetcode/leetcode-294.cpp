class Solution {
public:
    bool canWin(string currentState) {
        
        
        for(int index = 0; index < currentState.size() - 1; index++ ) {
            if( currentState[index] == '+' && currentState[index+1] == '+') {
                //try flip 
                currentState[index] = '-';
                currentState[index+1] = '-';
                bool win = canWin(currentState);
               
                if( win == false ) {
                    return true;
                }
                currentState[index] = '+';
                currentState[index+1] = '+';
                
            }
        }
        
        return false;
    }
  
};