class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> decrease_queue;
        vector<int> result;
        //this queue decrease in value and increase in index
        //step 1 generate first k
        for(int i=0;i<k;i++)
        {
            while(decrease_queue.empty()==false && nums[i] > nums[decrease_queue.back()])
            {
                decrease_queue.pop_back();
            }
            decrease_queue.push_back(i);
        }
        result.push_back(nums[decrease_queue.front()]);
        int start = 0;
        for(int cur=k;cur<nums.size();cur++)
        {
            start++;
            while(decrease_queue.empty() == false && start>decrease_queue.front())
            {
                decrease_queue.pop_front();
            }
            while(decrease_queue.empty() == false && nums[cur] > nums[decrease_queue.back()])
            {
                decrease_queue.pop_back();
            }
            decrease_queue.push_back(cur);
            result.push_back(nums[decrease_queue.front()]);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> indices;
        //this is monolithic queue keep the values from 
        // largest to smaller with index increasingly
        for(int idx = 0; idx < k; idx++) {
            
            while(indices.empty() == false && nums[idx] > nums[indices.back()]) {
                indices.pop_back();
            }
            
            indices.push_back(idx);
        }
        result.push_back(nums[indices.front()]);
        int start = 0;
        for(int idx = k; idx < nums.size(); idx++) {
            if(start == indices.front()) {
                indices.pop_front();
            }
            start++;
            while(indices.empty() == false && nums[idx] > nums[indices.back()]) {
                indices.pop_back();
            }
            
            indices.push_back(idx);
            result.push_back(nums[indices.front()]);
            
        }
        return result;
    }
};