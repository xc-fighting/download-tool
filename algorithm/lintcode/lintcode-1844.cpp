class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the minimum length of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsKII(vector<int> &nums, int k) {
        // write your code here
        // use the presum
        // also with the map which save the latest value index
        int sum = 0;
        int minSize = nums.size()+1;
        unordered_map<int,int> num_index;
        for( int index = 0; index < nums.size(); index++ ) {
            sum += nums[index];
            if( sum == k ) {
                minSize = min(minSize,index+1);
            }
            int remain = sum - k;
            if( num_index.find(remain) != num_index.end() ) {
                minSize = min(minSize, index- num_index[remain]);
            }
            num_index[sum] = index;
        }
        if(minSize == nums.size()+1) {
            return -1;
        }
        return minSize;
    }
};