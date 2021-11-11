class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        if( A.size() == 0 ) {
            return -1;
        }
        int left = 0;
        int right = A.size()-1;
        while( left + 1 < right ) {
             int mid = left + (right - left) /2;
             if( target == A[mid] ) {
                 return mid;
             }
             //check where is mid
             if( A[mid] > A[left] ) {
                 //on the left part
                 if( target > A[mid] || target < A[left] ) {
                     left = mid;
                 } 
                 else {
                     right = mid;
                 }
             }
             else {
                 //on the right part 
                 if( target < A[mid] || target > A[left] ) {
                     right = mid;
                 }
                 else {
                     left = mid;
                 }
             }
        }
        if( A[left] == target ) {
            return left;
        }
        if( A[right] == target ) {
            return right;
        }
        return -1;
    }
};