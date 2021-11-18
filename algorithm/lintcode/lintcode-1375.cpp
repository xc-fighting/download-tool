class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
    
    long long kDistinctCharacters(string &s, int k) {
        // Write your code here
        int left = 0;
        int right = 0;
        //[left,right) keep a valid window which has at least k distinct characters
        vector<int> chFreq(26,0);
        int numDistinct = 0;
        long long subArrays = 0;
        int len = s.size();
        while( left < s.size() ) {
            while( right < s.size() && numDistinct < k ) {
                char newChar = s[right];
                chFreq[newChar-'a']++;
                if( chFreq[newChar-'a'] == 1 ) {
                    numDistinct++;
                }
                right++;
            }
            //two case, one case that right < size and num distinct >= k
            //another case right < size and distinct still < k
            if( numDistinct >= k ) {
                //left , right-1 -> len-1
                // len-1 - (right-1) + 1 => len - right + 1
                
                subArrays += len-right+1;
            }
            char leftChar = s[left];
            chFreq[leftChar-'a']--;
            if( chFreq[leftChar-'a'] == 0 ) {
                numDistinct--;
            }
            left++;
        }
        return subArrays;
    }
};