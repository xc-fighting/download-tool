class Solution {
public:
    /**
     * @param colors: the colors of grids
     * @return: return the minimum step from position 0 to position n - 1
     */
    vector<int> expand(unordered_map<int,vector<int>>& colorPoses, 
                       unordered_set<int>& seen, unordered_set<int>& seenColor,
                       vector<int> &colors, 
                       int cur) {
        vector<int> result;
        int curColor = colors[cur];
        if( seenColor.find(curColor) == seenColor.end() ) {
              for( int pos: colorPoses[curColor] ) {
                
                if(seen.count(pos) == 0) {
                    result.push_back(pos);
                    seen.insert(pos);
                }
              }
              seenColor.insert(curColor);  
        }
        
        int prev = cur - 1;
        int next = cur + 1;
        if( prev >= 0 && seen.count(prev) == 0 ) {
            seen.insert(prev);
            result.push_back(prev);
           
        }
        if( seen.count(next) == 0 ) {
            seen.insert(next);
            result.push_back(next);
            
        }

        return result;
        
    }
    int minimumStep(vector<int> &colors) {
        // write your code here
        unordered_map<int,vector<int>> colorPoses;
        
        for( int pos = 0; pos < colors.size(); pos++ ) {
            if( colorPoses.find(colors[pos]) == colorPoses.end() ) {
                colorPoses[colors[pos]] = vector<int>();
            }
            colorPoses[colors[pos]].push_back(pos);
           
        }

        queue<int> states;
        unordered_set<int> seen;
        unordered_set<int> seenColor;
        int step = 0;
        states.push(0);
        seen.insert(0);

        while( states.empty() == false ) {
            int levelSize = states.size();
            for( int index = 0; index < levelSize; index++ ) {
               int pos = states.front();
               states.pop();
               if( pos == colors.size() -1 ) {
                   return step;
               }
               
               vector<int> next = expand(colorPoses,seen,seenColor,colors,pos);
               for(int nextPos: next) {
                   states.push(nextPos);
               }
            }
            step++;
        }
        
        return -1;
        

    }
};