//TLE
class Solution {
private:
    int result;
public:
    /**
     * @param nums: a list of integers
     * @param m: an integer
     * @return: return a integer
     */
    int splitArray(vector<int> &nums, int m) {
        // write your code here
        int len = nums.size();
        vector<int> presum(len,0);
        presum[0] = nums[0];
        result = INT_MAX;
        for(int i=1; i < len; i++)
        {
            presum[i] = presum[i-1] + nums[i];
        }
        traverse(nums,presum,0,m,INT_MIN);
        return result;
    }
    
    void traverse(vector<int>& nums,vector<int>& presum,int startIndex,int partsLeft,int curLargest)
    {
        if(startIndex == nums.size())
        {
            if(partsLeft == 0)
            {
                result = min(result,curLargest);
                return;
            }
            else
            {
                return;
            }
        }
        for(int index = startIndex; index < nums.size(); index++)
        {
            int prefix_sum = presum[index] - presum[startIndex] + nums[startIndex];
            traverse(nums,presum,index+1,partsLeft-1,max(curLargest,prefix_sum));
        }
        return;
    }
    

};



class Solution {
private:
    int result;
public:
    /**
     * @param nums: a list of integers
     * @param m: an integer
     * @return: return a integer
     */
    int splitArray(vector<int> &nums, int m) {
        // write your code here
        int len = nums.size();
        vector<long> presum(len,0);
        presum[0] = nums[0];
        result = INT_MAX;
        for(int i=1; i < len; i++)
        {
            presum[i] = presum[i-1] + nums[i];
           
        }
        cout<<presum[len-1]<<endl;
        vector<vector<long>> memo(len,vector<long>(m+1,-1));
        return (int)getMinLargestSum(nums,presum,memo,0,m);
        
    }
    
    long getMinLargestSum(vector<int>& nums,vector<long>& presum,vector<vector<long>> &memo,int startIndex,int partsLeft)
    {
        if(startIndex == nums.size())
        {
            if(partsLeft==0)
            {
                return 0;
            }
            return INT_MAX;
        }
        if(memo[startIndex][partsLeft] != -1)
        {
            return memo[startIndex][partsLeft];
        }
        long result = INT_MAX;
        for(int i=startIndex;i<nums.size();i++)
        {
            long curSum = presum[i] - presum[startIndex] + nums[startIndex];
            long nextMinLargest = getMinLargestSum(nums,presum,memo,i+1,partsLeft-1);
            if(nextMinLargest == INT_MAX)
            {
                continue;
            }
            long curMax = max(curSum,nextMinLargest);
            result = min(result,curMax);
        }
        memo[startIndex][partsLeft] = result;
        return memo[startIndex][partsLeft];
        
    }
    

};