class Solution {
public:
    /**
     * @param s: A string
     * @param wordSet: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &wordSet) {
        // write your code here
        int len = s.size();
        vector<int> memo(len+1,-1);
        memo[len] = 1;
        return canBreakStartFrom(s,0,memo,wordSet);
    }

    bool canBreakStartFrom(string& s,int curIndex,vector<int>& memo,unordered_set<string>& wordSet)
    {
        if(curIndex == s.size())
        {
            return true;
        }
        if(memo[curIndex] != -1)
        {
            if(memo[curIndex] == 1)
            {
                return true;
            }
            return false;
        }
        for(int endIndex = curIndex;endIndex < s.size();endIndex++)
        {
            string word = s.substr(curIndex,endIndex-curIndex+1);
            if(wordSet.find(word) != wordSet.end())
            {
                bool ret = canBreakStartFrom(s,endIndex+1,memo,wordSet);
                if(ret)
                {
                    memo[curIndex] = 1;
                    return true;
                }
            }
        }
        memo[curIndex] = 0;
        return false;
    }
};