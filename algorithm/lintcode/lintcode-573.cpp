class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */

    void markDistance(vector<vector<int>>& grid,int r, int c, vector<vector<int>>& distanceMap, vector<vector<int>>& counterMap) {
         int numRows = grid.size();
         int numCols = grid[0].size();

         int dx[4] = {0,0,1,-1};
         int dy[4] = {1,-1,0,0};

         unordered_set<int> visited;
         int curKey = r*numCols + c;
         visited.insert(curKey);
         queue<vector<int>> stateQueue;
         stateQueue.push(vector<int>({r,c}));
         int distance = 0;
         while( stateQueue.empty() == false ) {
             int levelSize = stateQueue.size();
             for( int counter = 0; counter < levelSize; counter++ ) {
                   vector<int> pos = stateQueue.front();
                   stateQueue.pop();
                   //do the expand here
                   for( int idx = 0; idx < 4; idx++ ) {
                       int newr = pos[0] + dx[idx];
                       int newc = pos[1] + dy[idx];
                       int newKey = newr * numCols + newc;
                       if( newr >= 0 && newr < numRows 
                            && newc >= 0 && newc < numCols 
                            && visited.find(newKey) == visited.end() 
                            && grid[newr][newc] == 0 ) {
                            
                          //  cout<<"get here"<<endl;
                            visited.insert(newKey);
                            distanceMap[newr][newc] += distance + 1;
                            counterMap[newr][newc]++;
                            stateQueue.push(vector<int>({newr,newc}));
                        }
                   }
             }
             distance++;
         }
         return;
    }
    int shortestDistance(vector<vector<int>> &grid) {
        // write your code here
        int numRows = grid.size();
        int numCols = grid[0].size();
        vector<vector<int>> distanceMap(numRows, vector<int>(numCols, INT_MIN));
        vector<vector<int>> counterMap(numRows, vector<int>(numCols, 0));
        vector<vector<int>> postList;
        for( int r = 0; r < numRows; r++ ) {
            for( int c = 0; c < numCols; c++ ) {
                if( grid[r][c] == 0 ) {
                    distanceMap[r][c] = 0;
                }
                if( grid[r][c] == 1) {
                    postList.push_back(vector<int>({r,c}));
                }
            }
        }
        
        int postOffices = postList.size();
        for( int index = 0; index < postList.size(); index++ ) {
           //  cout<<"start the marking"<<endl;
             markDistance(grid, postList[index][0], postList[index][1], distanceMap, counterMap);
        }

        int shortest = INT_MAX;
        for( int r = 0; r < numRows; r++ ) {
            for( int c = 0; c < numCols; c++ ) {
              //  cout<<distanceMap[r][c]<<",";
                if( grid[r][c] == 0 ) {
                    if( counterMap[r][c] == postOffices ) {
                        shortest = min(shortest, distanceMap[r][c]);
                    }
                }
            }
           // cout<<endl;
        }
        if( shortest == INT_MAX ) {
            return -1;
        }
        return shortest;

    }
};