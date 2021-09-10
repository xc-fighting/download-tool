class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        // Write your code here
        int len = words.size();
        int wordlen = words[0].size();
        if( len != wordlen ) {
            return false;
        }
        for( int i = 0; i < len; i++ ) {
            for( int j = 0; j <= i; j++ ) {
                 if( words[i][j] != words[j][i] ) {
                      return false;
                 }
            }
        }
        return true;
    }
};