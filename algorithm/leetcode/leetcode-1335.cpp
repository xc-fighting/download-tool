// TLE solution
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();
        if(len<d)
        {
            return -1;
        }
        
        return getMinDifficulty(jobDifficulty,0,d);
        
    }
    //brute force method
    int getMinDifficulty(vector<int>& jobDifficulty,int start,int dayRemain)
    {
        if(start == jobDifficulty.size())
        {
            if(dayRemain==0)
            {
                return 0;
            }
            return INT_MAX;
        }
        if(dayRemain==0)
        {
            return INT_MAX;
        }
        int result = INT_MAX;
        for(int cut=start;cut<jobDifficulty.size();cut++)
        {
            int curDifficulty = rangeMax(jobDifficulty,start,cut);
            int childRet = getMinDifficulty(jobDifficulty,cut+1,dayRemain-1);
            if(childRet != INT_MAX)
            {
                result = min(result,curDifficulty+childRet);
            }
        }
        return result;
    }
    int rangeMax(vector<int>& jobDifficulty,int left,int right)
    {
        int result = jobDifficulty[left];
        for(int i=left;i<=right;i++)
        {
            if(jobDifficulty[i]>result)
            {
                result = jobDifficulty[i];
            }
        }
        return result;
    }
};



class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();
        if(len<d)
        {
            return -1;
        }
        vector<vector<int>> memo(len,vector<int>(d+1,INT_MIN));
        return getMinDifficulty(memo,jobDifficulty,0,d);
        
    }
    //brute force method
    int getMinDifficulty(vector<vector<int>>& memo,vector<int>& jobDifficulty,int start,int dayRemain)
    {
        if(start == jobDifficulty.size())
        {
            if(dayRemain==0)
            {
                return 0;
            }
            return INT_MAX;
        }
        if(dayRemain==0)
        {
            return INT_MAX;
        }
        if(memo[start][dayRemain] != INT_MIN)
        {
            return memo[start][dayRemain];
        }
        int result = INT_MAX;
        for(int cut=start;cut<jobDifficulty.size();cut++)
        {
            int curDifficulty = rangeMax(jobDifficulty,start,cut);
            int childRet = getMinDifficulty(memo,jobDifficulty,cut+1,dayRemain-1);
            if(childRet != INT_MAX)
            {
                result = min(result,curDifficulty+childRet);
            }
        }
        memo[start][dayRemain]=result;
        return result;
    }
    int rangeMax(vector<int>& jobDifficulty,int left,int right)
    {
        int result = jobDifficulty[left];
        for(int i=left;i<=right;i++)
        {
            if(jobDifficulty[i]>result)
            {
                result = jobDifficulty[i];
            }
        }
        return result;
    }
};