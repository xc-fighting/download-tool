class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        vector<int> presum(len, 0);
        presum[0] = nums[0];
        for( int index = 1; index < len; index++ ) {
            presum[index] = presum[index-1] + nums[index];
        }
        
        int result = INT_MAX;
        for( int index = 0; index < len; index++ ) {
            if( presum[index] >= target ) {
                result = min(result, index+1);
                int remain = presum[index] - target;
                //find the last index when presum is smaller than or equal remain
                // len = index -(last+1) + 1 = index - last
                int left = 0;
                int right = index;
                while( left + 1 < right ) {
                    int mid = left + (right-left)/2;
                    if(presum[mid] < remain ) {
                        left = mid;
                    }
                    else if(presum[mid] == remain) {
                        left = mid;
                    }
                    else {
                        right = mid;
                    }
                }
                int lastIndex = -1;
                if(presum[right] <= remain ) {
                    lastIndex = right;
                }
                if(presum[left] <= remain ) {
                    lastIndex = left;
                }
                if(lastIndex != -1) {
                    result = min(result, index-lastIndex);
                }
            }
        }
        if( result == INT_MAX ) {
            return 0;
        }
        return result;
    }
};