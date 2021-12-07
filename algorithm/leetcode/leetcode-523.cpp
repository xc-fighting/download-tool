class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> remainIndices;
        
        remainIndices[0] = -1;
        
        int sum = 0;
        for(int idx = 0; idx < nums.size(); idx++) {
            sum += nums[idx];
            int remain = sum % k;
            if(remainIndices.find(remain) == remainIndices.end()) {
                remainIndices[remain] = idx;
            }
            
            else {
                int prev = remainIndices[remain];
                int curLen = idx - prev;
                if(curLen >= 2) {
                    return true;
                }
            }
        }
        return false;
        
    }
};
