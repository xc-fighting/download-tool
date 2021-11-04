class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left2Right(len, 1);
        vector<int> right2Left(len, 1);
        left2Right[0] = nums[0];
        right2Left[len-1] = nums[len-1];
        
        for( int index = 1; index < len; index++ ) {
             left2Right[index] = nums[index] * left2Right[index-1];
        }
        
        for( int index = len - 2; index >= 0; index-- ) {
             right2Left[index] = right2Left[index+1] * nums[index];
        }
        
        vector<int> result(len, 1);
        for( int index = 0; index < len; index++ ) {
             if( index == 0 ) {
                  result[index] = right2Left[1];
                  continue;
             }
             if( index == len - 1 ) { 
                 result[index] = left2Right[len-2];
                 continue;
             }
             
             result[index] = left2Right[index-1] * right2Left[index+1];
        }
        
        return result;
    }
};
