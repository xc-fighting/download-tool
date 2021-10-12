class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int largest = -1;
        for( int index = 0; index < nums.size(); index++ ) {
            if(nums[index] > largest) {
                largest = nums[index];
            }
        }
        int left = 1;
        int right = largest;
        while( left + 1 < right ) {
            int mid = left + (right-left)/2;
         //   cout<<mid<<endl;
            if( getSum(nums,mid) > threshold ) {
             //   cout<<"set left"<<endl;
                left = mid;
            }
            else {
               // cout<<"set right"<<endl;
                right = mid;
            }
        }
        if( getSum(nums,left) <= threshold ) {
            return left;
        }
        return right;
    }
    
    int getSum(vector<int>& nums,int divisor) {
        int sum = 0;
        for( int index = 0; index < nums.size(); index++ ) {
            if( nums[index] % divisor == 0 ) {
                sum += nums[index]/divisor;
            }
            else {
                sum += (nums[index]/divisor + 1);
            }
            
        }
        return sum;
    }
};