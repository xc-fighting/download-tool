class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> charFreq(256, 0);
        int types = 0;
        int leftIndex = 0;
        int rightIndex = 0;
        int result = 0;
        //[leftIndex,rightIndex) keep a window which contain at most k distinct chars
        while( rightIndex < s.size() ) {
             while( rightIndex < s.size() && types <= k ) {
                 result = max(result, rightIndex-leftIndex);
              //   cout<<leftIndex<<" "<<rightIndex<<endl;
                 char currentCh = s[rightIndex];
                 charFreq[currentCh]++;
                 if( charFreq[currentCh] == 1 ) {
                     types++;
                 }
                 
                 rightIndex++;
             }
            
             if( types <= k && rightIndex == s.size() ) {
                 
                 result = max(result, rightIndex-leftIndex);
                 break;
             }
            
             char leftChar = s[leftIndex];
             charFreq[leftChar]--;
             if( charFreq[leftChar] == 0 ) {
                 types--;
             }
             leftIndex++;
        }
        return result;
    }
};