class Compare
{
public:
  bool operator()(pair<string,int>& lhs,pair<string,int>& rhs)
  {
      if(lhs.second < rhs.second)
      {
          return false;
      }
      else if(lhs.second > rhs.second)
      {
          return true;
      }
      else
      {
          string leftstr = lhs.first;
          string rightstr = rhs.first;
          if(strcmp(leftstr.c_str(),rightstr.c_str()) < 0)
          {
              return true;
          }
          else
          {
              return false;
          }
      }
  }
};
class Solution {
public:
    /**
     * @param words: an array of string
     * @param k: An integer
     * @return: an array of string
     */
    vector<string> topKFrequentWords(vector<string> &words, int k) {
        // write your code here
        priority_queue<pair<string,int>,vector<pair<string,int>>,Compare> pq;
        map<string,int> wordFreq;
        for(int i=0;i<words.size();i++)
        {
            if(wordFreq.find(words[i])==wordFreq.end())
            {
                wordFreq[words[i]] = 0;
            }
            wordFreq[words[i]]++;
        }
        for(auto elem:wordFreq)
        {
            pq.push(elem);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<string> result(k,"");
        int index = k-1;
        while(pq.empty()==false)
        {
            string topstr = pq.top().first;
            pq.pop();
            result[index] = topstr;
            index--;
        }
        return result;
    }
};