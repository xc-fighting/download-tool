class Solution {
public:
    /**
     * @param A: An integer array
     * @param start: An integer
     * @param end: An integer
     * @return: the number of possible answer
     */
    int findRight(vector<int>& presum, int value, int left, int right) {
        //find the last elem which is less than or equal to value
        int l = left;
        int r = right;
        while(l + 1 < r) {
            int mid = l + (r - l) / 2;
            if(presum[mid] <= value) {
                l = mid;   
            }
            else {
                r = mid;
            }
        }
        if(presum[r] <= value) {
            return r;
        }
        return l;
        
    }

    int findLeft(vector<int>& presum, int value, int left, int right) {
        //find the left most elem which is larger than or equal to value
        int l = left;
        int r = right;
        while(l + 1 < r) {
           int mid = l + (r - l) / 2;
           if(presum[mid] >= value) {
               r = mid;
           }
           else {
               l = mid;
           }
        }
        if(presum[l] >= value) {
            return l;
        }
        
        return r;

       
        
    }
    int subarraySumII(vector<int> &A, int start, int end) {
        // write your code here
        int len = A.size();
        vector<int> presum(len, 0);
        presum[0] = A[0];
        for(int idx = 1; idx < len; idx++) {
            presum[idx] = A[idx] + presum[idx-1];
        }

        int result = 0;
        if(presum[0] >= start && presum[0] <= end) {
            result++;
        }

        for(int right = 1; right < len; right++) {
            int r = findRight(presum, presum[right]-start, 0 , right);
            int l = findLeft(presum, presum[right]-end, 0, right);
            result += r - l + 1;
        }
        return result;
    }
};
