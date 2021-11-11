class Solution {
public:
      bool check(vector<int>& nums, double average, int k) {
        double sum = 0.0f;
        for(int index = 0; index < k; index++ ) {
            sum = sum + (double)(nums[index] - average);
        }
        if( sum >= 0 ) {
            return true;
        }
        double prevMin = 0;
        double prev = 0.0;
        int left = 0;
        for( int index = k; index < nums.size(); index++ ) {
            sum += nums[index] - average;
            prev = prev + nums[left] - average;
            prevMin = min(prevMin, prev);
            
            left++;
            if( (sum - prevMin) >= 0 ) {
                return true;
            }
            
        }
        
        return false;
    }
    double findMaxAverage(vector<int>& nums, int k) {
        // write your code here
        int min = INT_MAX;
        int max = INT_MIN;
        for( int index = 0; index < nums.size(); index++ ) {
            if( nums[index] < min ) {
                min = nums[index];
            }
            if( nums[index] > max ) {
                max = nums[index];
            }
        }
        double error = INT_MAX;
        double left = min;
        double right = max;
        double prev = 0.0;
        while( error > 0.00001 ) {
            
            double mid = (double)(left) + (double)(right-left)*1.0/2.0f;
            //cout<<"middle:"<<mid<<endl;
            if( check(nums,mid,k) == true ) {
                left = mid;
            }
            else {
                right = mid;
            }
            error = abs(mid - prev);
            prev = mid;
        }
        return prev;
    }
};