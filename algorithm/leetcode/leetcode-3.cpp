class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int result = 0;
        
        vector<int> freqMap(256,0);
        while( right < s.size() ) {
            char cur = s[right];
            freqMap[cur]++;
            while(freqMap[cur] != 1) {
                char leftChar = s[left];
                freqMap[leftChar]--;
                left++;
            }
            result = max(result,right-left+1);
            right++;
        }
        return result;
        
    }
   
};