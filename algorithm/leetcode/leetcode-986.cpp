class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        if( firstList.size() == 0 || secondList.size() == 0 ) {
            return result;
        }
        int firstlistIndex = 0;
        int secondlistIndex = 0;
        while( firstlistIndex < firstList.size() 
               && secondlistIndex < secondList.size() ) {
            
            vector<int> firstInterval = firstList[firstlistIndex];
            vector<int> secondInterval = secondList[secondlistIndex];
            int minEnd = min( firstInterval[1], secondInterval[1] );
            int maxStart = max( firstInterval[0], secondInterval[0] );
            if( maxStart <= minEnd ) {
                //there is an overlap, put that into result
                vector<int> overlap(2,-1);
                overlap[0] = maxStart;
                overlap[1] = minEnd;
                result.push_back(overlap);
            }
            
            //check who end first, move that one
            if( firstInterval[1] == secondInterval[1] ) {
                firstlistIndex++;
                secondlistIndex++;
            }
            else if( firstInterval[1] < secondInterval[1] ) {
                firstlistIndex++;
            }
            else {
                 secondlistIndex++;
            }
        }
        
        return result;
    }
};