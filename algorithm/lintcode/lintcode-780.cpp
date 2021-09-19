class Solution {
public:
    /**
     * @param s: The input string
     * @return: Return all possible results
     */
    /*
            ( ) ( ) ) ( )
    curIndex  start from 0 if see ( delete it or not 
    curIndex normal character continue 
    curIndex ) check whether left-right > 0 if > 0 then can choose delete or not
    if ==0 or less than, must delete it

    base case:
     when curIndex == s.size()
       check whether it is balanced

    you keep a vector which store all the longest valid ones
    
    */
    vector<string> removeInvalidParentheses(string &s) {
        // Write your code here
        vector<string> result;
        result.push_back("");
        traverse(s,0,"",result,0,0);
        unordered_set<string> filter;
        for(string str: result) {
            filter.insert(str);
        }
        return vector<string>(filter.begin(),filter.end());
        
    }

    void traverse( string& input, int curIndex, 
                   string curString, vector<string>& result, 
                   int leftCount, int rightCount ) {
        
        
        // base condition
        if( curIndex == input.size() ) {
            // cout<<"the current string:"<<curString<<endl;
             if( leftCount != rightCount ) {
                 return;
             }
             // leftCount == rightCount, the curString is balanced
             int curMaxLen = result[0].size();
           //  cout<<"current max len:"<<curMaxLen<<endl;
             if( curString.size() == curMaxLen ) {

                 result.push_back(curString);
                 return;
             }
             if( curString.size() > curMaxLen ) {
                 result.clear();
                 result.push_back(curString);
                 return;
             }

             //when it is larger
             return;
        }

        if( input[curIndex] != '(' && input[curIndex] != ')' ) {
             traverse( input, curIndex+1, curString + input[curIndex], result, leftCount, rightCount );
             return;
        }

        if( input[curIndex] == '(' ) {
            //delete it 
            traverse( input, curIndex+1, curString, result, leftCount, rightCount );
            // not delete it 
            traverse( input, curIndex+1, curString + '(', result, leftCount+1, rightCount );
            return;
        }

        if( input[curIndex] == ')' ) {
            if( leftCount <= rightCount ) {
                //you must delete it 
                traverse(input, curIndex+1, curString, result, leftCount, rightCount );
            }
            else {
                 //delete it 
                traverse( input, curIndex+1, curString, result, leftCount, rightCount );
                // not delete it 
                traverse( input, curIndex+1, curString + ')', result, leftCount, rightCount+1 );
            }
        }
        return;


    }

};