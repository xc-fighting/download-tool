class Solution {
public:
    /**
     * @param matrix: the matrix for calculation.
     * @return: return the max area after operation at most once.
     */
    void expand(vector<vector<int>>& matrix, unordered_map<int,int>& islandSize,
                vector<vector<int>>& belongMap, 
                int row, int col, 
                int islandId) {

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        queue<vector<int>> stateQueue;

        vector<int> start({row,col});
        belongMap[row][col] = islandId;
        int landSize = 0;
        stateQueue.push(start);
        while( stateQueue.empty() == false ) {
            vector<int> frontState = stateQueue.front();
          
            stateQueue.pop();
            landSize++;
            for( int index = 0; index < 4; index++ ) {
                int newRow = frontState[0] + dx[index];
                int newCol = frontState[1] + dy[index];
                if( newRow >= 0 && newRow < matrix.size() 
                    && newCol >= 0 && newCol < matrix[0].size() 
                    && matrix[newRow][newCol] == 1 && belongMap[newRow][newCol] == -1 ) {
                      
                      belongMap[newRow][newCol] = islandId;
                      vector<int> newState({newRow,newCol});

                      stateQueue.push(newState);

                }
            }
        }
        islandSize[islandId] = landSize;
      //  cout<<"landSize"<<landSize<<endl;
        return;

    }
    int maxArea(vector<vector<int>> &matrix) {
        // write your code here.
        unordered_map<int,int> islandSize;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> belongMap(rows, vector<int>(cols,-1));
        for( int row = 0; row < rows; row++ ) {
            for( int col = 0; col < cols; col++ ) {
                 if( matrix[row][col] == 0 ) {
                     continue;
                 }
                 if( belongMap[row][col] == -1 ) {
                //     cout<<"here"<<endl;
                     int islandId = row * cols + col;
                     
                     expand(matrix,islandSize,belongMap,row,col,islandId);
                 }
                 

            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int result = 0;
        for( int row = 0; row < rows; row++ ) {
            for( int col = 0; col < cols; col++ ) {
                if(matrix[row][col] == 0 ) {
                    int maxSize = 0;
                    set<int> islandIds;

                    for( int index = 0; index < 4; index++ ) {

                         int newRow = row + dx[index];
                         int newCol = col + dy[index];
                        // cout<<newRow<<","<<newCol<<endl;
                         if( newRow >= 0 && newRow < matrix.size() 
                             && newCol >= 0 && newCol < matrix[0].size()
                             && matrix[newRow][newCol] == 1 ) {
                                  islandIds.insert(belongMap[newRow][newCol]);
                             }

                    }
                    for(int id: islandIds) {
                        maxSize += islandSize[id];
                    }
                  //  cout<<maxSize<<endl;
                    maxSize++;
                    result = max(result,maxSize);
                }
            }
        }
        if( result == 0 ) {
            return matrix.size() * matrix[0].size();
        }
        return result;
    }
};