//TLE solution
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            if(nums[0]%k==0)
            {
                return 1;
            }
            return 0;
        }
        int len = nums.size();
        //sumArr[i] represent the prefix sum fron index 0 to index i
        vector<int> sumArr(len,0);
        sumArr[0] = nums[0];
        for(int i=1;i<len;i++)
        {
            sumArr[i] = nums[i]+sumArr[i-1];
        }
        int result = 0;
        for(int start = 0;start<len;start++)
        {
            for(int end = start;end<len;end++)
            {
                int intervalSum = sumArr[end] - sumArr[start] + nums[start];
                if(intervalSum%k==0)
                {
                    result++;
                }
            }
        }
        return result;
    }
};


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> reminder_freq;
        reminder_freq[0] = 1;
        int sum = 0;
        int result = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            int remain = sum % k;
            if(remain<0)
            {
                 remain = remain + k;
            }
            if(reminder_freq.find(remain) != reminder_freq.end())
            {
                result += reminder_freq[remain];
            }
            reminder_freq[remain]++;
            
        }
        
        return result;
    }
};