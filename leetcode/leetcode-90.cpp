class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> curSet;
        vector<bool> seen(nums.size(),false);
        subSetStartWith(nums,0,seen,curSet,result);
        return result;
    }
    
    void subSetStartWith(vector<int>& nums, int index, vector<bool>& seen,vector<int>& curSet, vector<vector<int>>& result)
    {
        if(index == nums.size())
        {
            result.push_back(vector<int>(curSet));
            return;
        }
        result.push_back(vector<int>(curSet));
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i] == nums[i-1] && seen[i-1] == false)
            {
                continue;
            }
            seen[i] =true;
            curSet.push_back(nums[i]);
            subSetStartWith(nums,i+1,seen,curSet,result);
            curSet.pop_back();
            seen[i] = false;
        }
        
    }
};