class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @param k: An integer
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if( nums.size() == 0 ) {
            return vector<int>();
        } 
        // write your code here
        deque<int> maxQueue;
        //step 1: do the initialize operation
        for(int i=0;i<=k-1;i++) {
            while( maxQueue.empty() == false && nums[i] > nums[maxQueue.back()] ) {
                maxQueue.pop_back();
            }
            maxQueue.push_back(i);
        }
        vector<int> result;
        int firstMaxIndex = maxQueue.front();
        result.push_back(nums[firstMaxIndex]);
        int start = 0;
        for(int end = k; end < nums.size(); end++) {
            start++;
            while( maxQueue.empty() == false && start > maxQueue.front() ) {
                maxQueue.pop_front();
            }
            while( maxQueue.empty() == false && nums[end] > nums[maxQueue.back()] ) {
                 maxQueue.pop_back();
            }
            maxQueue.push_back(end);
            result.push_back(nums[maxQueue.front()]);
        }
        return result;
    }
};