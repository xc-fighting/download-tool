class Solution {
public:
    /**
     * @param str: the string
     * @param dict: the dictionary
     * @return: return words which  are subsequences of the string
     */
    bool checkExist(string& longstr, string& shortstr) {
        int largeIndex = 0;
        int smallIndex = 0;
        while( largeIndex < longstr.size() && smallIndex < shortstr.size() ) {
            if( longstr[largeIndex] == shortstr[smallIndex] ) {
                 largeIndex++;
                 smallIndex++;
            }
            else {
                largeIndex++;
            }
        }
        if(smallIndex < shortstr.size()) {
            return false;
        }
        return true;
    }
    vector<string> findWords(string &str, vector<string> &dict) {
        // write your code here.
        vector<string> result;
        for( int index = 0; index < dict.size(); index++ ) {
             if( checkExist(str,dict[index]) ) {
                  result.push_back(dict[index]);
             }
        }
        return result;
    }
};
