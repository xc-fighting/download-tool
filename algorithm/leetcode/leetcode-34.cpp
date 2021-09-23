class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size()-1;
        vector<int> result(2,-1);
        if(nums.size() == 0) {
            return result;
        }
        while( start + 1 < end ) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) {
                end = mid;
            }
            else if( nums[mid] < target ) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        if( nums[start] == target) {
            result[0] = start;
        }
        else if( nums[end] == target ) {
            result[0] = end;
        }
        if(result[0] == -1) {
            return result;
        }
        
        start = result[0];
        end = nums.size()-1;
        while(start + 1 < end) {
            int mid = start + (end - start)/2;
            if( nums[mid] == target ) {
                start = mid;
            }
            else if( nums[mid] > target ) {
                end = mid -1;
            }
            else {
                start = mid + 1;
            }
        }
        if(nums[end] == target) {
            result[1] = end;
        }
        else {
            result[1] = start;
        }
        return result;
    }
};