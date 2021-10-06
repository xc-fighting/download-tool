class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges = 0;
        queue<vector<int>> rottenQueue;
        for( int row = 0; row < grid.size(); row++ ) {
            for( int col = 0; col < grid[0].size(); col++ ) {
                 if( grid[row][col] == 1 ) {
                     freshOranges++;
                 }
                 else if(grid[row][col] == 2){
                     vector<int> rotten(2,-1);
                     rotten[0] = row;
                     rotten[1] = col;
                     rottenQueue.push(rotten);
                 }
            }
        }
        if( freshOranges == 0 ) {
            return 0;
        }
        int minute = 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while( rottenQueue.empty() == false ) {
            int rottenSize = rottenQueue.size();
            for( int size = 0; size < rottenSize; size++ ) {
                vector<int> curPos = rottenQueue.front();
                rottenQueue.pop();
                for( int index = 0; index < 4; index++ ) {
                    int newRow = curPos[0] + dx[index];
                    int newCol = curPos[1] + dy[index];
                    if( newRow < 0 || newRow >= grid.size() 
                        || newCol < 0 || newCol >= grid[0].size() 
                        || grid[newRow][newCol] != 1 ) {
                           continue;
                    }
                    vector<int> newRotten(2,-1);
                    newRotten[0] = newRow;
                    newRotten[1] = newCol;
                    grid[newRow][newCol] = 2;
                    freshOranges--;
                    rottenQueue.push(newRotten);
                }
            }
            minute++;
        }
        if(freshOranges == 0){
            return minute-1;
        }
        
        return -1;
    }
};