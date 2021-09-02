//TLE solution
class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsK(vector<int> &nums, int k) {
        // write your code here
        int len = nums.size();
        vector<int> presum(len,0);
        presum[0] = nums[0];
        for(int i=1;i<len;i++)
        {
            presum[i] = nums[i] + presum[i-1];
        }
        int result = 0;
        for(int i=0;i<len;i++)
        {
            for(int j=i;j<len;j++)
            {
                int rangeSum = presum[j] - presum[i] + nums[i];
                if(rangeSum == k)
                {
                    result++;
                }
            }
        }
        return result;
    }
};


//wrong answer
class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsK(vector<int> &nums, int k) {
        int len = nums.size();
        unordered_map<int,int> presum_freq;
        vector<int> presum(len+1,0);
        // presum[i] means sum of first i elements
        int result = 0;
        presum_freq[0] = 1;
        for(int i=1;i<=len;i++)
        {
            presum[i] = presum[i-1] + nums[i-1];
            cout<<i<<"->"<<presum[i]<<endl;
            if(presum_freq.find(presum[i])==presum_freq.end())
            {
                presum_freq[presum[i]] = 0;
            }
            presum_freq[presum[i]]++;
        }

        for(int i=1;i<=len;i++)
        {
            int targetSum = presum[i] - k;
            if(presum_freq.find(targetSum) != presum_freq.end())
            {
                result += presum_freq[targetSum];
            }
        }
        return result;

    }
};


class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsK(vector<int> &nums, int k) {
        int len = nums.size();
        unordered_map<int,int> presum_freq;
        vector<int> presum(len+1,0);
        // presum[i] means sum of first i elements
        int result = 0;
        presum_freq[0] = 1;
        for(int i=1;i<=len;i++)
        {
            presum[i] = presum[i-1] + nums[i-1];
            int leftsum = presum[i] - k;
            if(presum_freq.find(leftsum) != presum_freq.end())
            {
                result += presum_freq[leftsum];
            }
           // cout<<i<<"->"<<presum[i]<<endl;
            if(presum_freq.find(presum[i])==presum_freq.end())
            {
                presum_freq[presum[i]] = 0;
            }
            presum_freq[presum[i]]++;
        }

        return result;

    }
};