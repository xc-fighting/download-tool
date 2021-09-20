

//deduplicate method
class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> curSet;
        explore(result,nums,0,curSet);
        return result;
    }

    void explore(vector<vector<int>>& result, vector<int>& nums, int curIndex,vector<int>& curSet) {
        
        result.push_back(vector<int>(curSet));
        if(curIndex == nums.size()) {
            return;
        }
        for(int index = curIndex; index < nums.size(); index++) {
             curSet.push_back(nums[index]);
             explore(result,nums,index+1,curSet);
             curSet.pop_back();
        }
    }
};