
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, 
                             vector<string>& sources, vector<string>& targets) {
        // invalid operation means: overlap with other or source not found
        // for loop of check generate the valid intervals
        int len = indices.size();
        vector<int> validMap(len,-1);
        int largestEnd = -1;
        for(int i=0; i<len; i++) {
            //check substring first
            string source = sources[i];
            string substr = s.substr(indices[i], source.size());
            if(substr.compare(source) != 0) {
                validMap[i] = 0;
                continue;
            }
            
            if(largestEnd == -1) {
                largestEnd = i;
            }
            else {
                int right = indices[largestEnd] + sources[largestEnd].size() - 1;
                if(indices[i] <= right) {
                    validMap[i] = 0;
                    validMap[largestEnd] = 0;
                    largestEnd = -1;
                }
                else {
                    largestEnd = i;
                    validMap[i] = 1;
                    
                }
            }
            
        }
        
        //set up the result
        string result = "";
        int splitStart = 0;
        for(int i=0;i<indices.size();i++) {
            if(validMap[i]==0) {
                continue;
            }
            else {
                int checkPoint = indices[i];
                string original = s.substr(splitStart, checkPoint-splitStart);
                result = result + original + targets[i];
                splitStart = checkPoint + sources[i].size();
                
            }
        }
        if(splitStart < s.size()) {
            result = result + s.substr(splitStart);
        }
        return result;
        
    }
};