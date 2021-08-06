//TLE 
class Solution {
public:
    
    int gcd(int x,int y)
    {
        if(y==0)
        {
            return x;
        }
        if(x<y)
        {
            return gcd(y,x);
        }
        return gcd(y,x%y);
    }
    
    int maxScore(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> gcd_arr(len,vector<int>(len,-1));
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                int gcdVal = gcd(nums[i],nums[j]);
                gcd_arr[i][j] = gcdVal;
                gcd_arr[j][i] = gcdVal;
               // cout<<nums[i]<<" "<<nums[j]<<" "<<gcd_arr[i][j]<<endl;
            }
        }
        vector<bool> visited(len,false);
        return getMaxScore(gcd_arr,visited,1,len/2);
        
    }
    
    int getMaxScore(vector<vector<int>>& gcd_arr,vector<bool>& visited,int curOp,int totalOp)
    {
        if(curOp > totalOp)
        {
            return 0;
        }
        int len = visited.size();
        int result = 0;
        for(int i=0;i<len;i++)
        {
            
            for(int j=i+1;j<len;j++)
            {
                if(visited[i] == false && visited[j] == false)
                {
                    visited[i] = true;
                    visited[j] = true;
                    int cur = curOp*gcd_arr[i][j] + getMaxScore(gcd_arr,visited,curOp+1,totalOp);
                    result = max(result,cur);
                    visited[i] = false;
                    visited[j] = false;
                }
            }
        }
        return result;
    }
};