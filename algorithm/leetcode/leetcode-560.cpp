class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumFreq;
        sumFreq[0] = 1;
        int totalSum = 0;
        int result = 0;
        
        for( int index = 0; index < nums.size(); index++ ) {
            totalSum += nums[index];
           
            int remain = totalSum - k;
            
            if( sumFreq.find(remain) != sumFreq.end() ) {
                
                result += sumFreq[remain];
            }
            if( sumFreq.find(totalSum) == sumFreq.end() ) {
                sumFreq[totalSum] = 0;
            }
            sumFreq[totalSum]++;
        }
        return result;
    }
};
