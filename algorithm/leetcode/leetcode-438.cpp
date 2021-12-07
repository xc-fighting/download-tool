class Solution {
public:
    bool checkEqual(vector<int>& smap, vector<int>& pmap) {
        for(int idx = 0; idx < 26; idx++ ) {
            if( smap[idx] == pmap[idx] ) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> result;
        
        if( p.size() > s.size() ) {
            return result;
        }
        vector<int> pmap(26, 0);
        for( int idx = 0; idx < p.size(); idx++ ) {
            char ch = p[idx];
            pmap[ch-'a']++;
        }
        
        vector<int> smap(26,0);
        
        //initialize
        int start = 0;
        for( int idx = 0; idx < p.size(); idx++ ) {
            char ch = s[idx];
            smap[ch-'a']++;
        }
        if( checkEqual(smap,pmap) ) {
            result.push_back(0);
        }
        
        for( int idx = p.size(); idx < s.size(); idx++ ) {
            char newCh = s[idx];
            smap[newCh -  'a']++;
            smap[s[start] -'a']--;
            start++;
            if( checkEqual(smap,pmap) ) {
                result.push_back(start);
            }
        }
        return result;
    }
};
