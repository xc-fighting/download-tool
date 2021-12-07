class Solution {
public:
    vector<string> expand(string input) {
        vector<string> result;
        string temp = input;
        for(int idx = 0; idx < input.size(); idx++) {
            char prev = temp[idx];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                if(prev == ch) {
                    continue;
                }
                temp[idx] = ch;
                result.push_back(temp);
            }
            temp[idx] = prev;
        }
        return result;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> dict;
        for(string word: wordList) {
            dict.insert(word);
        }
        
        if(dict.find(endWord) == dict.end()) {
            return 0;
        }
        
        queue<string> strQueue;
        strQueue.push(beginWord);
        
        unordered_set<string> seen;
        seen.insert(beginWord);
        
        int step = 0;
        while(strQueue.empty() == false) {
            int size = strQueue.size();
            
            for(int idx = 0; idx < size; idx++) {
                 string frontWord = strQueue.front();
                 if(frontWord.compare(endWord) == 0) {
                     return step+1;
                 }
                 strQueue.pop();
                 vector<string> newWords = expand(frontWord);
                 for(string newWord: newWords) {
                   //  cout<<"expand:"<<newWord<<endl;
                     if(dict.count(newWord) > 0 && seen.find(newWord) == seen.end()) {
                         
                         seen.insert(newWord);
                         strQueue.push(newWord);
                     }
                 }
            }
            
            step++;
        }
        
        return 0;
        
    }
};
