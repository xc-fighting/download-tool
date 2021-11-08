class Solution {
public:
    void reverse(vector<int>& nums, int start ,int end ) {
        while( start < end ) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
        return;
    }
    void swap(vector<int>& input, int left, int right) {
        int temp = input[left];
        input[left] = input[right];
        input[right] = temp;
        return;
    }
    void nextPermutation(vector<int>& nums) {
        //traverse from right 
        
        int right = nums.size()-1;
        int abnormal = -1;
        while( right > 0 ) {
            //if keep increasing from right to left
            if( nums[right] <= nums[right-1]) {
                right--;
            }
            else {
                abnormal = right - 1;
                break;
            }
        }
        if( abnormal == -1 ) {
            reverse(nums,0, nums.size()-1);
            return;
        }
        int justLargerIndex = nums.size() - 1;
        while( justLargerIndex > abnormal ) {
            if( nums[justLargerIndex] > nums[abnormal] ) {
                break;
            }
            else{
                justLargerIndex--;
            }
        }
        swap(nums, abnormal, justLargerIndex);
        reverse(nums,abnormal+1, nums.size()-1);
        return;
        
    }
};