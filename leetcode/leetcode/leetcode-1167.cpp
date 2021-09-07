class Comp
{
  public:
    bool operator()(int& previous,int& next)
    {
        if(previous<next)
        {
            return false;
        }
        return true;
    }
};
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
       priority_queue<int,vector<int>,Comp> pq;
       for(int i=0;i<sticks.size();i++)
       {
           pq.push(sticks[i]);
       }
       int result = 0;
       while(pq.size()>=2)
       {
           int s1 = pq.top();
           pq.pop();
           int s2 = pq.top();
           pq.pop();
           int newstick = s1 + s2;
           result = result + newstick;
           pq.push(newstick);
       }
       return result;
        
    } 
   
};