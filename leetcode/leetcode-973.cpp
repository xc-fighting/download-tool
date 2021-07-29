class Compare
{
  //think from back to left because when pq pop it is from back to front
  // so if new coming one which is second argument rhs larger, keep it, return true for what comp expect
  // if it is smaller, need to swap, so return false will trigger that
  public:
    bool operator()(const vector<int>& lhs,const vector<int>& rhs) const
    {
         int dis1 = lhs[0]*lhs[0] + lhs[1]*lhs[1];
         int dis2 = rhs[0]*rhs[0] + rhs[1]*rhs[1];
         if(dis1<dis2)
         {
              return true;
         }
         return false;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        int len = points.size();
        for(int i=0;i<len;i++)
        {
            pq.push(points[i]);
            if(pq.size()>k)
            {
                 pq.pop();
            }
        }
        vector<vector<int>> result(k,vector<int>(2,-1));
        int index = k-1;
        while(index>=0)
        {
             vector<int> temp = pq.top();
             result[index][0] = temp[0];
             result[index][1] = temp[1];
             pq.pop();
             index--;
        }
        return result;
    }
};