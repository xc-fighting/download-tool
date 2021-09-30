class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while( left + 1 < right ) {
            int mid = left + (right-left)/2;
            if(nums[mid] == target) {
                 return mid;
            }
            //check mid is in upper part or lower part
            // compare with the left
            if( nums[mid] > nums[left] ) {
                 //the mid is in left part
                if( target > nums[mid] ) {
                    left = mid;
                }
                else {
                    //target < nums[mid]
                    //two case
                    //case 1
                    if( target < nums[left] ) {
                        left = mid;
                    }
                    else {
                        right = mid;
                    }
                }
            }
            else {
                //the mid is in right part
                if( target < nums[mid] ) {
                    right = mid;
                }
                else {
                    if( target < nums[left] ) {
                        left = mid;
                    }
                    else {
                        right = mid;
                    }
                }
            }
        }
        
        if( nums[left] == target ) {
            return left;
        }
        
        if( nums[right] == target ) {
            return right;
        }
        return -1;
    }
};