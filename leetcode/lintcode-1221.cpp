bool compare(string& lhs,string& rhs)
{
    if(lhs.size() < rhs.size())
    {
        return true;
    }
    return false;
}
class Solution {
public:
    /**
     * @param words: List[str]
     * @return: return List[str]
     */
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        // write your code here
      //  cout<<"pass0"<<endl;
        sort(words.begin(),words.end(),compare);
    //    cout<<"pass1"<<endl;
        unordered_set<string> dict;
        for(string word:words)
        {
            dict.insert(word);
        }
       // cout<<"pass2"<<endl;
        vector<string> result;
        for(int i=words.size()-1;i>=0;i--)
        {
            if(words[i].size()==0)
            {
                continue;
            }
            vector<int> memo(words[i].size()+1,-1);
            memo[words[i].size()] = 1;
            dict.erase(words[i]);
            if(canBreak(dict,words[i],0,memo))
            {
                
                result.push_back(words[i]);
            }
            dict.insert(words[i]);
        }
        return result;
    }
    bool canBreak(unordered_set<string>& dict,string input,int start,vector<int>& memo)
    {
        if(start>=input.size())
        {
            return true;
        }
        if(memo[start] !=-1)
        {
            if(memo[start] ==1)
            {
                return true;
            }
            return false;
        }
        for(int end = start;end<input.size();end++)
        {
            string prefix = input.substr(start,end-start+1);
            
           
            if(dict.find(prefix) != dict.end())
            {
                
                if(canBreak(dict,input,end+1,memo))
                {
                    memo[start] = 1;
                    return true;
                }
            }
        }
        memo[start] = 0;
        return false;

    }
};