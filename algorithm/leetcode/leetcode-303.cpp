class NumArray {
private:
    vector<int> presum;
public:
    NumArray(vector<int>& nums) {
        
        int len = nums.size();
        
        presum = vector<int>(len, 0);
        
        presum[0] = nums[0];
        
        for( int index = 1; index < nums.size(); index++ ) {
            
            presum[index] = presum[index-1] + nums[index];
        }
    }
    
    int sumRange(int left, int right) {
        int rightSum = presum[right];
        if( left == 0 ) {
            return rightSum;
        }
        return rightSum - presum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */