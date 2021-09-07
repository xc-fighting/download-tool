class Solution {
public:
    /**
     * @param nums: the input array
     * @param target: the target number
     * @return: return the target pair
     */
    vector<vector<int>> twoSumVII(vector<int> &nums, int target) {
        // write your code here
        map<int,int> value_index;
        vector<vector<int>> result;
        for(int i=0;i<nums.size();i++)
        {
            int current = nums[i];
            int remain = target - current;
            if(value_index.find(remain)!=value_index.end())
            {
                vector<int> temp;
                temp.push_back(value_index[remain]);
                temp.push_back(i);
                result.push_back(temp);
            }
            value_index[current] = i;
        }
        return result;
    }
};