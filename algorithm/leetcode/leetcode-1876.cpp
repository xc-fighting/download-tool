class Solution {
public:
    bool isGood(vector<int>& memo)
    {
        for(int i=0;i<26;i++)
        {
            if(memo[i]>1)
            {
                return false;
            }
        }
        return true;
    }
    int countGoodSubstrings(string s) {
        if(s.size() < 3)
        {
            return 0;
        }
        vector<int> freqMap(26,0);
        int result = 0;
        freqMap[s[0]-'a']++;
        freqMap[s[1]-'a']++;
        freqMap[s[2]-'a']++;
        if(isGood(freqMap))
        {
            result++;
        }
        int left = 0;
        int right = 3;
        while(right<s.size())
        {
            char ch_new = s[right];
            char ch_pre = s[left];
            freqMap[ch_new-'a']++;
            freqMap[ch_pre-'a']--;
            if(isGood(freqMap))
            {
                result++;
            }
            left++;
            right++;
        }
        return result;
    }
};