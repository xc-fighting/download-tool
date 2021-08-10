class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<pair<int,int>> currentList;
        generateCombination(currentList,result,target,0,candidates);
        return result;
    }
    
    void generateCombination(vector<pair<int,int>>& currentList,vector<vector<int>>& result,
                            int sumRemain,int currentIndex, vector<int>& candidates)
    {
        if(sumRemain==0)
        {
            //touch the base
            vector<int> temporary;
            for(pair<int,int> elem:currentList)
            {
                int num = elem.first;
                int freq = elem.second;
                for(int i=0;i<freq;i++)
                {
                    temporary.push_back(num);
                }
            }
            if(temporary.size()!=0)
            {
                result.push_back(vector<int>(temporary));
            }
            return;
        }
        if(currentIndex == candidates.size())
        {
            return;
        }
        
        //in the normal case
        int totalCount = sumRemain / candidates[currentIndex];
        for(int i=0;i<=totalCount;i++)
        {
            //remember, include the case when not choose at all
            pair<int,int> currentChoice;
            currentChoice.first = candidates[currentIndex];
            currentChoice.second = i;
            currentList.push_back(currentChoice);
            generateCombination(currentList,result,
                                sumRemain-i*candidates[currentIndex],currentIndex+1,
                                candidates);
            currentList.pop_back();
        }
        return;
    }
};