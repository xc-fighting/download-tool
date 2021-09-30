// false solution, maybe work ?
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


//correct solution
struct OP {
public:
    int start;
    int end;
    string source;
    string target;
    OP(int i, string src, string dst) {
        this->start = i;
        this->end = start + src.size() - 1;
        this->source = src;
        this->target = dst;
    }
};
bool compare(OP& lhs, OP& rhs) {
    if(lhs.start < rhs.start) {
        return true;
    }
    return false;
};
struct comp {
public:
    //the one which have largest end come at top
    bool operator()(OP& lhs, OP& rhs) {
        if( lhs.end > rhs.end ) {
            return false;
        }
        return true;
    }
};
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<OP> opList;
        for( int index = 0; index < indices.size(); index++ ) {
             string source = sources[index];
             string original_source = s.substr(indices[index],source.size());
             if( source.compare(original_source) == 0 ) {
                 OP item(indices[index],sources[index],targets[index]);
                 opList.push_back(item);
             }
             
        }
        sort(opList.begin(),opList.end(),compare);
        priority_queue<OP,vector<OP>,comp> pq;
        for(int index = 0; index < opList.size(); index++ ) {
            int curStart = opList[index].start;
            bool overlap = false;
            if( pq.empty()==false && pq.top().end >= curStart ) {
                pq.pop();
                overlap = true;
            }
            if(overlap == false) {
                pq.push(opList[index]);
            }
        }
        
        string result = "";
        int originalEnd = s.size()-1;
        while(pq.empty() == false) {
            OP topOp = pq.top();
            pq.pop();
            int replaceEnd = topOp.end;
            int originalLen = originalEnd - replaceEnd;
            string originalLeft = s.substr(replaceEnd+1,originalLen);
            result = topOp.target + originalLeft + result;
            originalEnd = topOp.start-1;
        }
        if( originalEnd >= 0 ) {
            result = s.substr(0,originalEnd+1) + result;
        }
        return result;
        
    }
};