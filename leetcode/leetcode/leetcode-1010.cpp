class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int> reminder_freq;
        int totalPair = 0;
        for(int i=0;i<time.size();i++)
        {
            int currentRemain = time[i] % 60;
            int otherRemain;
            if(currentRemain==0)
            {
                otherRemain = 0;
            }
            else
            {
                otherRemain = 60 - currentRemain;
            }
            
            if(reminder_freq.find(otherRemain) != reminder_freq.end())
            {
                totalPair += reminder_freq[otherRemain];
            }
            if(reminder_freq.find(currentRemain) == reminder_freq.end())
            {
                reminder_freq[currentRemain] = 0;
            }
            reminder_freq[currentRemain]++;
        }
        return totalPair;
    }
};