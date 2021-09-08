//Error algorithm
struct Compare
{
  public:
    bool operator()(pair<char,int>& lhs,pair<char,int>& rhs)
    {
        int lfreq = lhs.second;
        int rfreq = rhs.second;
        if(lfreq >= rfreq)
        {
            return true;
        }
        return false;
    }
};
class Solution {
public:
    /**
     * @param tasks: the given char array representing tasks CPU need to do
     * @param n: the non-negative cooling interval
     * @return: the least number of intervals the CPU will take to finish all the given tasks
     */
    int leastInterval(string &tasks, int n) {
        // write your code here
        unordered_map<char,int> ch_freq;
        for(int i=0;i<tasks.size();i++)
        {
            if(ch_freq.find(tasks[i])==ch_freq.end())
            {
                ch_freq[tasks[i]] = 0;
            }
            ch_freq[tasks[i]]++;
        }

        priority_queue<pair<char,int>,vector<pair<char,int>>,Compare> pq;
        for(auto item:ch_freq)
        {
            pq.push(item);
        }
        
        int result = 0;
        while(pq.empty()==false)
        {
            int componentSize = pq.size();
            cout<<"component size is:"<<componentSize<<endl;
            pair<char,int> topElem = pq.top();
            pq.pop();
            int freq = topElem.second;
            cout<<"the freq is:"<<freq<<endl;
            vector<pair<char,int>> buffer;
            while(pq.empty()==false)
            {
               pair<char,int> temp = pq.top();
               pq.pop();
               int remain = temp.second - freq;
               if(remain > 0)
               {
                   temp.second = remain;
                   buffer.push_back(temp);
               }
            }
            for(int i=0;i<buffer.size();i++)
            {
                pq.push(buffer[i]);
            }
            if(pq.empty()==false)
            {
               result += freq*max(componentSize,n+1);
            }
            else
            {
                result += (freq-1)*max(componentSize,n+1) + componentSize;
            }
        }
        return result;

    }
};


//do the real simulation:
struct Compare
{
  public:
    bool operator()(pair<char,int>& lhs,pair<char,int>& rhs)
    {
        int lfreq = lhs.second;
        int rfreq = rhs.second;
        if(lfreq >= rfreq)
        {
            return false;
        }
        return true;
    }
};
class Solution {
public:
    /**
     * @param tasks: the given char array representing tasks CPU need to do
     * @param n: the non-negative cooling interval
     * @return: the least number of intervals the CPU will take to finish all the given tasks
     */
    int leastInterval(string &tasks, int n) {
        // write your code here
        unordered_map<char,int> ch_freq;
        for(int i=0;i<tasks.size();i++)
        {
            if(ch_freq.find(tasks[i])==ch_freq.end())
            {
                ch_freq[tasks[i]] = 0;
            }
            ch_freq[tasks[i]]++;
        }

        priority_queue<pair<char,int>,vector<pair<char,int>>,Compare> pq;
        for(auto item:ch_freq)
        {
            pq.push(item);
        }
        
        int result = 0;
        
        while(pq.empty()==false)
        {
           int popSize = n+1;
           vector<pair<char,int>> buffer;
           int actualSize = 0;
           
           while(pq.empty()==false && popSize > 0)
           {
              pair<char,int> topElem = pq.top();
              pq.pop();
              popSize--;
              actualSize++;
              topElem.second = topElem.second - 1;
              if(topElem.second > 0)
              {
                 buffer.push_back(topElem);
              }
              
           }
           
           for(int i=0;i<buffer.size();i++)
           {
               pq.push(buffer[i]);
           }
           if(pq.empty()==false)
           {
               result += n+1;
           }
           else
           {
               result += actualSize;
               
           }
        }
        return result;

    }
};