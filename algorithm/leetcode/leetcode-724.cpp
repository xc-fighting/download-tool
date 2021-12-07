class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum = 0;
        for(int idx = 0; idx < nums.size(); idx++) {
            sum += nums[idx];
        }
        int presum = 0;
        for(int idx = 0; idx < nums.size(); idx++) {
            int leftSum = -1;
            int rightSum = -1;
            presum += nums[idx];
            if(idx == 0) {
                
                leftSum = 0;
                rightSum = sum - nums[0];
                
            }
            else if(idx == nums.size() - 1) {
                leftSum = sum - nums[idx];
                rightSum = 0;
            }
            
            else {
                leftSum = presum - nums[idx];
                rightSum = sum - presum;
            }
            
            if(leftSum == rightSum) {
                return idx;
            }
        }
        
        return -1;
    }
};
