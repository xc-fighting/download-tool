class Solution {
public:

    void generate(string start,string end,
                  unordered_map<string,set<string>> word_parent,
                  vector<string>& currentList,vector<vector<string>>& result)
    {
        if(strcmp(start.c_str(),end.c_str())==0)
        {
            currentList.push_back(end);
            result.push_back(vector<string>(currentList));
            currentList.pop_back();
            return;
        }
      //  cout<<start<<endl;
        currentList.push_back(start);
        set<string> parents = word_parent[start];
        for(auto str:parents)
        {
           // cout<<parents[i]<<endl;
            generate(str,end,word_parent,currentList,result);
        }
        currentList.pop_back();
        return;
    }
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        vector<vector<string>> result;
        dict.insert(end);
        unordered_map<string,set<string>> word_parent;
        unordered_map<string,int> seen_distance;
        queue<string> wordQueue;
        for(auto item:dict)
        {
            word_parent[item] = set<string>();
            seen_distance[item] = INT_MAX;
        }
        seen_distance[start] = 0;
        wordQueue.push(start);
        while(wordQueue.empty()==false)
        {
            string firstWord = wordQueue.front();
            wordQueue.pop();
            int curDistance = seen_distance[firstWord];
            string nextWord = firstWord;
            for(int i=0;i<nextWord.size();i++)
            {
                char original = nextWord[i];
                for(char ch = 'a';ch <= 'z';ch++)
                {
                    if(ch == original)
                    {
                        continue;
                    }
                    nextWord[i] = ch;
                    if(dict.find(nextWord) != dict.end())
                    {
                         int newDistance = curDistance + 1;
                         if(newDistance < seen_distance[nextWord])
                         {
                             seen_distance[nextWord] = newDistance;
                             word_parent[nextWord].clear();
                             word_parent[nextWord].insert(firstWord);
                             wordQueue.push(nextWord);
                         }
                         else if(newDistance == seen_distance[nextWord])
                         {
                             word_parent[nextWord].insert(firstWord);
                             wordQueue.push(nextWord);
                         }

                    }
                    else
                    {
                        continue;
                    }
                    
                }
                nextWord[i] = original;
            }
        }
        vector<string> temp;
        generate(end,start,word_parent,temp,result);
        for(int i=0;i<result.size();i++)
        {
            reverse(result[i].begin(),result[i].end());
        }
        return result;

    }
};



class Solution {
public:
    
 
    vector<string> expand(string word,unordered_set<string>& dict)
    {
        vector<string> result;
        string next = word;
        for(int i=0;i<next.size();i++)
        {
            char original = next[i];
            for(char ch ='a'; ch<='z'; ch++)
            {
                next[i] = ch;
                if(next.compare(word) !=0 && dict.find(next) != dict.end())
                {
                    result.push_back(next);
                }
            }
            next[i] = original;
        }

        return result;
    }

    void generate(vector<vector<string>>& result,vector<string>& curlist,
                  unordered_map<string,set<string>>& graph,
                  string start,string end,
                  unordered_map<string,int>& distances)
    {
        if(start.compare(end)==0)
        {
            curlist.push_back(start);
            result.push_back(vector<string>(curlist));
            curlist.pop_back();
            return;
        }
        curlist.push_back(start);
        for(string next:graph[start])
        {
            //filter out some same level words
          //  if(distances[next] != distances[start] + 1)
         //   {
         //       continue;
         //   }
            generate(result,curlist,graph,next,end,distances);
        }
        curlist.pop_back();
        return;
    }
   
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
          dict.insert(start);
          dict.insert(end);
          unordered_map<string,int> distances;
          unordered_map<string,set<string>> graph;
          for(auto word:dict)
          {
              graph[word] = set<string>();
          }
          int step = 0;
          queue<string> word_queue;
          word_queue.push(start);
          distances[start] = 0;
          bool findEnd = false;
          while(word_queue.empty()==false)
          {
              int size = word_queue.size();
              for(int i=0;i<size;i++)
              {
                  
                  string frontword = word_queue.front();
                  word_queue.pop();
                  vector<string> nextwords = expand(frontword,dict);
                  for(string next:nextwords)
                  {
                      if(next.compare(end)==0)
                      {
                          findEnd = true;
                      }
                      if(distances.find(next)==distances.end())
                      {
                          distances[next] = step+1;
                         
                      }
                      if(distances[next] == step + 1)
                      {
                          graph[frontword].insert(next);
                          word_queue.push(next);
                      }
                      
                  }
              }
              if(findEnd)
              {
                  break;
              }
              step++;
          }
          /*
           void generate(vector<vector<string>>& result,vector<string>& curlist,
                  unordered_map<string,vector<string>>& graph,
                  string start,string end,
                  unordered_map<string,int>& distances)
          
          */
         vector<vector<string>> result;
         vector<string> curlist;
         generate(result,curlist,graph,start,end,distances);
         return result;

    }
};