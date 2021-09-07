// TLE 
class Solution {
public:
    /**
     * @param ages: 
     * @return: nothing
     */
    bool sendRequest(int ageA,int ageB)
    {
        if(ageB <= 0.5*ageA + 7 || (ageB > ageA) || (ageB > 100 && ageA < 100))
        {
            return false;
        }
        return true;
    }
    int numFriendRequests(vector<int> &ages) {
        
        int result = 0;
        for(int i=0;i<ages.size()-1;i++)
        {
            for(int j=i+1;j<ages.size();j++)
            {
                if(sendRequest(ages[i],ages[j]))
                {
                    result++;
                }
                if(sendRequest(ages[j],ages[i]))
                {
                    result++;
                }
            }
        }
        return result;
    }
};


class Solution {
public:
    /**
     * @param ages: 
     * @return: nothing
     */
    bool sendRequest(int ageA,int ageB)
    {
        if(ageB <= 0.5*ageA + 7 || (ageB > ageA) || (ageB > 100 && ageA < 100))
        {
            return false;
        }
        return true;
    }
    int numFriendRequests(vector<int> &ages) {
        unordered_map<int,int> age_freq;
        for(int i=0;i<ages.size();i++)
        {
            if(age_freq.find(ages[i])==age_freq.end())
            {
                age_freq[ages[i]] = 0;
            }
            age_freq[ages[i]]++;
        }
        int result = 0;
        for(auto item1:age_freq)
        {
            for(auto item2:age_freq)
            {
                int age1 = item1.first;
                int age2 = item2.first;
                int freq1 = item1.second;
                int freq2 = item2.second;
                if(age1==age2)
                {
                    if(freq1>1 && sendRequest(age1,age2))
                    {
                        result += freq1*(freq1-1);
                    }
                }
                else
                {
                    if(sendRequest(age1,age2))
                    {
                        result += freq1*freq2;
                    }
                   
                }
            }
        }
        return result;
    }
};