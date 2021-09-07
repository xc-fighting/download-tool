// tle solution
class Compare
{
  public:
     bool operator()(pair<int,int>& lhs,pair<int,int>& rhs)
     {
         if(lhs.second <= rhs.second)
         {
             return true;
         }
         else
         {
             return false;
         }
     }
};
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        for(int i=0;i<inventory.size();i++)
        {
            pq.push(pair<int,int>(i,inventory[i]));
        }
        int sum = 0;
        int currentOrder = 0;
        while(currentOrder < orders)
        {
            pair<int,int> topElem = pq.top();
            pq.pop();
            
            sum = (sum + topElem.second) % 1000000007;
            currentOrder++;
            pq.push(pair<int,int>(topElem.first,topElem.second-1));
        }
        return sum;
    }
};