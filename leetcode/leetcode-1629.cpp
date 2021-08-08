class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> durationMap(26,0);
        int longestDuration = 0;
        int start = 0;
        for(int i=0;i<keysPressed.size();i++)
        {
            char key = keysPressed[i];
            int duration = releaseTimes[i] - start;
            start = releaseTimes[i];
            durationMap[key-'a'] = max(duration,durationMap[key-'a']);
            longestDuration = max(longestDuration,durationMap[key-'a']);
        }
        char candidate;
        for(int i=25;i>=0;i--)
        {
            if(durationMap[i]==longestDuration)
            {
                candidate = (char)(i+'a');
                break;
            }
        }
        return candidate;
    }
};