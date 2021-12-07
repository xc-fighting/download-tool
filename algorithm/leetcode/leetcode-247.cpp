class Solution {
public:
    vector<string> getStrobogrammatic(int n) {
        vector<string> result;
        if(n == 0) {
            result.push_back("");
            return result;
        }
        if(n == 1) {
            result.push_back("0");
            result.push_back("1");
            result.push_back("8");
            return result;
        }
        
        vector<string> candidates = getStrobogrammatic(n-2);
        for(int idx = 0; idx < candidates.size(); idx++) {
            string str1 = "1" + candidates[idx] + "1";
            string str0 = "0" + candidates[idx] + "0";
            string str8 = "8" + candidates[idx] + "8";
            string str6 = "6" + candidates[idx] + "9";
            string str9 = "9" + candidates[idx] + "6";
            result.push_back(str0);
            result.push_back(str1);
            result.push_back(str6);
            result.push_back(str8);
            result.push_back(str9);
        }
        
        return result;
    }
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;
        if(n == 1) {
            result.push_back("0");
            result.push_back("1");
            result.push_back("8");
            return result;
        }
        vector<string> candidates = getStrobogrammatic(n);
        for(string word: candidates) {
            if(word[0] == '0') {
                continue;
            }
            result.push_back(word);
        }
        
        return result;
    }
};
