class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        int left = 0;
        int right = nums.size() - 1;
        while( left + 1 < right ) {
            int mid = left + (right-left) / 2;
            if( nums[mid] < nums[mid+1] ) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        if( nums[left] < nums[right] ) {
            return nums[right];
        }
        return nums[left];
    }
};