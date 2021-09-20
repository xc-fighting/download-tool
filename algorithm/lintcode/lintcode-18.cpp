class Solution {
public:
    /**
     * @param nums: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> curSet;
        traverse(result,curSet,0,nums);
        return result;
    }

    void traverse(vector<vector<int>>& result, vector<int>& curSet, int curIndex, vector<int>& nums) {
        
        result.push_back(vector<int>(curSet));
        for(int index = curIndex; index < nums.size(); index++ ) {
            if( index > curIndex && nums[index] == nums[index-1]) {
                continue;
            }
            curSet.push_back(nums[index]);
            traverse(result,curSet,index+1,nums);
            curSet.pop_back();
        }
    }
};