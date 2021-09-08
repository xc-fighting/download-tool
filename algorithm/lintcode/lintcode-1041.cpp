class Compare
{
public:
   bool operator()(pair<char,int>& lhs, pair<char,int>& rhs)
   {
       int lfreq = lhs.second;
       int rfreq = rhs.second;
       if( lfreq < rfreq )
       {
           return true;
       }
       return false;
   }
};
class Solution {
public:
    /**
     * @param S: a string
     * @return: return a string
     */
    string reorganizeString(string &S) {
        // write your code here
        unordered_map<char,int> ch_freq;
        for(int i=0;i<S.size();i++)
        {
            if(ch_freq.find(S[i]) == ch_freq.end())
            {
                ch_freq[S[i]] = 0;
            }
            ch_freq[S[i]]++;
        }
      
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;
        for(auto item: ch_freq)
        {
           
           pq.push(item);
        }
       
        string result = "";
        while(pq.empty() == false)
        {
            if(pq.size()==1)
            {
                pair<char,int> topPair = pq.top();
                pq.pop();
                if(topPair.second == 1)
                {
                    result = result + topPair.first;
                }
                else
                {
                    return "";
                }
            }
            else
            {
                pair<char,int> firstPair = pq.top();
                pq.pop();
                pair<char,int> secondPair = pq.top();
                pq.pop();
                int freq = min(firstPair.second, secondPair.second);
                for(int i=0;i<freq;i++)
                {
                    result = result + firstPair.first + secondPair.first;
                }
                firstPair.second -= freq;
                secondPair.second -= freq;
                if(firstPair.second != 0)
                {
                    pq.push(firstPair);
                }
                if(secondPair.second != 0)
                {
                    pq.push(secondPair);
                }
            }
        }
        return result;
    }
};