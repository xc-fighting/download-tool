//TLE
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> pairStack;
        int index = 0;
        while( index < s.size() ) {
            char ch = s[index];
            if( pairStack.empty() == false ) {
                pair<char,int> topPair = pairStack.top();
                pairStack.pop();
                if( topPair.first == ch ) {
                    int newFreq = topPair.second + 1;
                    if( newFreq == k ) {
                        //do nothing
                    }
                    else {
                        topPair.second = newFreq;
                        pairStack.push(topPair);
                    }
                }
                else {
                    pairStack.push(topPair);
                    pairStack.push(pair<char,int>(ch,1));
                }
            }
            else {
                pairStack.push(pair<char,int>(ch,1));
            }
            index++;
        }
        string result = "";
        while( pairStack.empty() == false ) {
            pair<char,int> topPair = pairStack.top();
            pairStack.pop();
            char ch = topPair.first;
            int freq = topPair.second;
            for( int i = 0; i < freq; i++ ) {
                result = ch + result;
            }
        }
        return result;
        
    }
};