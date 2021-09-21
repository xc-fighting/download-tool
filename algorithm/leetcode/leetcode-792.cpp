class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        unordered_map<string,bool> checkWord;
        for(string word:words) {
            if( checkWord.find(word) != checkWord.end() ) {
                if(checkWord[word] == true) {
                    result++;
                }
                continue;
            }
            if(isSubSequence(s,word)) {
                result++;
                checkWord[word] = true;
            }
            else {
                checkWord[word] = false;
            }
        }
        return result;
    }
    
    bool isSubSequence(string& input, string substr) {
        if( substr.size() > input.size() ) {
            return false;
        }
        int indexLarge = 0;
        int indexSmall = 0;
        while( indexLarge < input.size() && indexSmall < substr.size() ) {
            if( substr[indexSmall] == input[indexLarge] ) {
                indexSmall++;
            }
            indexLarge++;
        }
        if(indexSmall == substr.size()) {
            return true;
        }
        return false;
    }
};