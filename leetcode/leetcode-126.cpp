//TLE
class Solution {
    //use dfs for path generate
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dictionary;
        for(int i=0;i<wordList.size();i++)
        {
            dictionary.insert(wordList[i]);
        }
        vector<vector<string>> result;
        vector<string> currentPath;
        set<string> seen;
        int minLen = INT_MAX;
        generatePath(beginWord,endWord,dictionary,seen,currentPath,result,&minLen);
        return result;
        
    }
    void generatePath(string currentWord,
                      string endWord,
                      set<string>& dictionary,
                      set<string>& seen,
                      vector<string>& curPath,
                      vector<vector<string>>& pathset,
                      int* minLen)
    {
      //  cout<<"current:"<<currentWord<<endl;
        //base case 1
        if(curPath.size() > (*minLen) )
        {
            //prune here because no need to check more
            return;
        }
        //base case 2
        if(strcmp(currentWord.c_str(),endWord.c_str()) == 0)
        {
          //  cout<<"find"<<endl;
            curPath.push_back(currentWord);
            seen.insert(currentWord);
            if(curPath.size()==(*minLen))
            {
                //find the min path, another one
              //  cout<<"find a equal path"<<curPath.size()<<endl;
                pathset.push_back(vector<string>(curPath));
            }
            else if( curPath.size() < (*minLen) )
            {
                //it is less than minLen which means a shorter one find
                //update the minLen
              //  cout<<"find a smaller path"<<curPath.size()<<endl;
                *minLen = curPath.size();
                pathset.clear();
                pathset.push_back(vector<string>(curPath));
            }
            curPath.pop_back();
            seen.erase(currentWord);
            return;
        }
        
        seen.insert(currentWord);
        curPath.push_back(currentWord);
        for( int pos = 0; pos < currentWord.size(); pos++ )
        {
             char original = currentWord[pos];
             for( char replace = 'a'; replace <= 'z'; replace++ )
             {
                 if( replace == original )
                 {
                      continue;
                 }
                 currentWord[pos] = replace;
                 if(dictionary.find(currentWord) != dictionary.end() && seen.find(currentWord) == seen.end() )
                 {
                     generatePath(currentWord,endWord,dictionary,seen,curPath,pathset,minLen);
                 }
                 currentWord[pos] = original;
             }
        }
        seen.erase(currentWord);
        curPath.pop_back();
        return;
        
    }
};