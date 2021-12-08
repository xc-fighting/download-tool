class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);
    }
    
    void swap(vector<int>& input, int left, int right) {
        int temp = input[left];
        input[left] = input[right];
        input[right] = temp;
        return;
    }
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        
        int pivot = nums[left];
        //[left,cur] keeps a window which is larger or equal to pivot
        int cur= left;
        //[rightBorder,right] keeps a window which is smaller than pivot
        int rightBorder= right + 1;
        while(cur < rightBorder) {
            if(nums[cur] >= pivot) {
                cur++;
            }
            else {
                swap(nums, rightBorder-1, cur);
                rightBorder--;
            }
        }
        
        swap(nums, left, rightBorder-1);
        int pivotIndex = rightBorder - 1;
        if(pivotIndex == k-1) {
            return pivot;
        }
        
        else if(pivotIndex < (k-1)) {
            return quickSelect(nums, pivotIndex+1, right, k);
        }
        
        else {
            
            return quickSelect(nums, left, pivotIndex-1, k);
        }
        
    }
};
