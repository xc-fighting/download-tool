class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
         if(k == 0 ) {
             return 0;
         }
         int left = 0;
         int right = 0;
         vector<int> chFreq(256, 0);
         int numDistinct = 0;
         int candidate = 0;
         while( right < s.size() ) {
             char newCh = s[right];
             chFreq[newCh]++;
             if( chFreq[newCh] == 1 ) {
                 numDistinct++;
             }
             while( left < s.size() && numDistinct > k ) {
              //   cout<<"num distinct:"<<numDistinct<<endl;
                 char leftCh = s[left];
                 chFreq[leftCh]--;
                 if( chFreq[leftCh] == 0 ) {
                     numDistinct--;
                 }
                 left++;
             }

             if( left <= right ) {
                 //when program running here, it is already the valid answer
                 int len = right - left + 1;
                 candidate = max(candidate, len);
             }
             
             right++;
         }
         return candidate;
    }
};