class Solution {
public:
    void swap(string& input,int left,int right) {
        char temp = input[left];
        input[left] = input[right];
        input[right] = temp;
        return;
    }
    void expand(unordered_set<string>& dict, string start, 
                unordered_map<string,int>& group, 
                unordered_set<string>& seen)  {
        seen.insert(start);
        group[start] = 1;
        queue<string> stateQueue;
        stateQueue.push(start);
        while(stateQueue.empty() == false) {
            string frontStr = stateQueue.front();
            stateQueue.pop();
            int len = frontStr.size();
            for(int leftIdx = 0; leftIdx < len - 1; leftIdx++ ) {
                for( int rightIdx = leftIdx + 1; rightIdx < len; rightIdx++ ) {
                     swap(frontStr, leftIdx, rightIdx);                    
                     if( dict.find(frontStr) != dict.end() && seen.find(frontStr) == seen.end() ) {
                         seen.insert(frontStr);
                         stateQueue.push(frontStr);
                         group[start]++;
                     }
                     swap(frontStr,leftIdx, rightIdx);
                }
            }
        }
        return;
    }
    /**
     * @param A: a string array
     * @return: the number of groups 
     */
    int numSimilarGroups(vector<string> &A) {
        // Write your code here
        unordered_set<string> dict;
        unordered_map<string,int> group;
        unordered_set<string> seen;
        for( int idx = 0; idx < A.size(); idx++ ) {
            dict.insert(A[idx]);
        }
        int groupNum = 0;
        for( int idx = 0; idx < A.size(); idx++ ) {
            if(seen.find(A[idx]) == seen.end()) {
                 groupNum++;
                 expand(dict,A[idx],group,seen);
            }
        }
        return groupNum;
    }
};