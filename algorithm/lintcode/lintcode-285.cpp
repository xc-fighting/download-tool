//TLE solution
class Solution {
public:
    /**
     * @param arr: the height of all buildings
     * @return: how many buildings can he see at the location of each building
     */
   
    void checkAndPush(vector<int>& input, stack<int>& decreaseStack, int idx) {
          if(decreaseStack.empty() == true ) {
                decreaseStack.push(idx);
            }
            else {
                int curHeight = input[idx];
                while( decreaseStack.empty() == false 
                    && input[decreaseStack.top()] <= curHeight ) {
                    decreaseStack.pop();
                }
                decreaseStack.push(idx);
            }
    }
    vector<int> check(vector<int>& input, int pos) {
        //check from 0 to pos
        vector<int> res(2,0);
        stack<int> decreaseStack;
        for(int idx = 0; idx < pos; idx++) {
            checkAndPush(input, decreaseStack, idx);
        }
        res[0] = decreaseStack.size();
        //check from end of list to pos
        while( decreaseStack.empty() == false ) {
            decreaseStack.pop();
        }
        int len = input.size();
        for( int idx = len - 1; idx > pos; idx-- ) {
            checkAndPush(input, decreaseStack, idx);
        }
        res[1] = decreaseStack.size();
        return res;
    }
    vector<int> tallBuilding(vector<int> &arr) {
        // Write your code here.
        int len = arr.size();
        vector<int> result(len , 1);
        for( int idx = 0; idx < len; idx++ ) {
            vector<int> res = check(arr, idx);
            result[idx] += res[0];
            result[idx] += res[1];
        }
        return result;
    }
};

//normal solution
class Solution {
public:
    /**
     * @param arr: the height of all buildings
     * @return: how many buildings can he see at the location of each building
     */
    
    vector<int> tallBuilding(vector<int> &input) {
        // Write your code here.
        int len = input.size();
        vector<int> result(len , 1);
        stack<int> decreaseStack;
        for( int idx = 0; idx < input.size(); idx++ ) {
            result[idx] += decreaseStack.size();
            if(decreaseStack.empty() == true ) {
                
                decreaseStack.push(idx);
            }
            else {
                int curHeight = input[idx];
                while( decreaseStack.empty() == false 
                    && input[decreaseStack.top()] <= curHeight ) {
                    decreaseStack.pop();
                }
               
                decreaseStack.push(idx);
            }
        }
        while( decreaseStack.empty() == false ) {
            decreaseStack.pop();
        }
        for( int idx = len - 1; idx >= 0; idx-- ) {
            result[idx] += decreaseStack.size();
            if(decreaseStack.empty() == true ) {
               
                decreaseStack.push(idx);
            }
            else {
                int curHeight = input[idx];
                while( decreaseStack.empty() == false 
                    && input[decreaseStack.top()] <= curHeight ) {
                    decreaseStack.pop();
                }
               
                decreaseStack.push(idx);
            }
        }
        return result;
    }
};