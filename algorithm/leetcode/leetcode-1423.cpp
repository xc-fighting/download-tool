class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        vector<int> presum(len,0);
        presum[0] = cardPoints[0];
        int totalSum = cardPoints[0];
        for( int index = 1; index < len; index++ ) {
            presum[index] = cardPoints[index] + presum[index - 1];
            totalSum += cardPoints[index];
        }
        
        if( k == len ) {
            return totalSum;
        }
        int left = 0;
        int right = len - k - 1;
        int result = 0;
        while( right < len ) {
            int windowSum = presum[right] - presum[left] + cardPoints[left];
            int points = totalSum - windowSum;
            result = max( result, points);
            left++;
            right++;
        }
        return result;
        
    }
};