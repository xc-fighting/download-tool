//TLE solution
class Solution {
public:
    /**
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        // write your code here
        vector<string> result;
        string cur = "";
        traverse(num,cur,result,0,target,-1,'$',0);
        unordered_set<string> filter;
        for(string candidate:result) {
            filter.insert(candidate);
        }
        return vector<string>(filter.begin(), filter.end());
    }

    void traverse(string& num, string curString, 
                  vector<string>& result,int totalSum, 
                  int target, int preNum, 
                  char op, int index) {

        if( index == num.size() ) {
            //cout<<curString<<endl;
            if(totalSum == target) {
                int len = curString.size();
                result.push_back(curString.substr(0,len-1));
            }
            return;
        }
        
        int curNumber = 0;
        for(int i = index; i< num.size(); i++) {
            if( num[index] == '0' && i > index ) {
                break;
            }
            curNumber = curNumber*10 + num[i] - '0';
            int newTotal = -1;
            int newPreNum = -1;
            if( op == '*' ) {  
                 newPreNum = preNum * curNumber;
                 newTotal = totalSum - preNum + newPreNum;
            }
            else if(op == '-') {
                 newPreNum = -curNumber;
                 newTotal = totalSum - curNumber;
            }
            else {
                 newPreNum = curNumber;
                 newTotal = totalSum + curNumber;
            }
            traverse(num,(curString+to_string(curNumber)+"+"),result,newTotal,target,newPreNum,'+',i+1);
            traverse(num,(curString+to_string(curNumber)+"-"),result,newTotal,target,newPreNum,'-',i+1);
            traverse(num,(curString+to_string(curNumber)+"*"),result,newTotal,target,newPreNum,'*',i+1);
            
        }
        return;
    }
};