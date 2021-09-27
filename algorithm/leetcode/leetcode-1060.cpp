class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int len = nums.size();
        int max = nums[len-1];
        vector<bool> existMap(max+1, false);
        for( int i = 0; i < len; i++ ) {
            int value = nums[i];
            existMap[value] = true;
        }
        
        int order = 0;
        for(int i=nums[0]; i<=max; i++ ) {
            if( existMap[i] == false ) {
                order++;
            }
            if(order == k) {
                return i;
            }
        }
        
        if(order < k ){
            int diff = k - order;
            return max + diff;
        }
        
        return -1;
    }
};