class Compare
{
public:
   bool operator()(vector<int>& lhs,vector<int>& rhs)
   {
       // value freq target
       int leftVal = lhs[0];
       int rightVal = rhs[0];
       int leftFreq = lhs[1];
       int rightFreq = rhs[1];
       int target = lhs[2];
       int leftDelta = abs(leftVal-target);
       int rightDelta = abs(rightVal - target);
       if(leftDelta < rightDelta)
       {
            return false;
       }
       else if(leftDelta > rightDelta)
       {
           return true;
       }
       else 
       {
           if(leftVal <= rightVal)
           {
               return false;
           }
           else
           {
               return true;
           }
       }
   }
};
class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        unordered_map<int,int> num_freq;
        for(int i=0;i<A.size();i++)
        {
            if(num_freq.find(A[i]) == num_freq.end())
            {
                num_freq[A[i]] = 0;
            }
            num_freq[A[i]]++;
        }
        for(auto elem:num_freq)
        {
            int value = elem.first;
            int freq = elem.second;
            vector<int> pushElem(3,-1);
            pushElem[0] = value;
            pushElem[1] = freq;
            pushElem[2] = target;
            pq.push(pushElem);
        }
        int remain = k;
        vector<int> result;
        while(remain > 0)
        {
            vector<int> topElem = pq.top();
            pq.pop();
            int topVal = topElem[0];
            int topFreq = topElem[1];
            if( remain >= topFreq )
            {
                for(int i=0;i<topFreq;i++)
                {
                    result.push_back(topVal);
                }
                remain -= topFreq;
            }
            else
            {
                for(int i=0;i<remain;i++)
                {
                    result.push_back(topVal);
                }
                remain = 0;
            }
        }
        return result;
    }
};