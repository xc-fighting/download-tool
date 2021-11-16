class Solution {
public:
    /**
     * @param side_length: the length of a side of the lake (it's a square)
     * @param lake_grid: a 2D matrix representing the lake 0= ice, 1= snowbank, -1= hole 
     * @param albert_row: row of Albert's snowbank
     * @param albert_column: column of Albert's snowbank 
     * @param kuna_row: row of Kuna's snowbank 
     * @param kuna_column: column of Kuna's snowbank
     * @return: a bool - whether Albert can escape
     */
    
    vector<int> goAhead(vector<vector<int>> &lake_grid, int row, int col, int dx,int dy) {
        int curRow = row + dx;
        int curCol = col + dy;
        int rows = lake_grid.size();
        int cols = lake_grid[0].size();
        while( curRow >= 0 && curRow < rows && curCol >= 0 && curCol < cols ) {
            if( lake_grid[curRow][curCol] == 1 || lake_grid[curRow][curCol] == -1 ) {
                break;
            } 
            //when it is ice then keep moving
            curRow = curRow + dx;
            curCol = curCol + dy;
        }
        vector<int> temp(2,-1);
        if( curRow >= 0 && curRow < rows && curCol >= 0 && curCol < cols ) {
            if( lake_grid[curRow][curCol] == 1 ) {
                 temp[0] = curRow;
                 temp[1] = curCol;
                 return temp;
            }
            else {
                return temp;
            }
        }
        //reach the bank
        temp[0] = rows*rows;
        temp[1] = rows*rows;
        return temp;
    }
    bool lakeEscape(int side_length, vector<vector<int>> &lake_grid, int albert_row, int albert_column, int kuna_row, int kuna_column) {
        // write your code here
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        vector<vector<int>> visited(side_length,vector<int>(side_length,0));
        queue<vector<int>> stateQueue;
        vector<int> startState({albert_row,albert_column});
        visited[albert_row][albert_column] = 1;
        stateQueue.push(startState);
        bool canReachBank = false;
        while( stateQueue.empty() == false ) {
            vector<int> frontState = stateQueue.front();
            stateQueue.pop();
            int row = frontState[0];
            int col = frontState[1];
            for( int index = 0; index < 4; index++ ) {
                 vector<int> nextPos = goAhead(lake_grid,row,col,dx[index],dy[index]);
                 if( nextPos[0] == side_length * side_length ) {
                     canReachBank = true;
                 }
                 else if( nextPos[0]== -1 ) {
                     continue;
                 }
                 else {
                     if( visited[nextPos[0]][nextPos[1]] == 0 ) {
                          visited[nextPos[0]][nextPos[1]] = 1;
                          vector<int> temp({nextPos[0],nextPos[1]});
                          stateQueue.push(temp);
                     }
                 }
            }
        }

        if( visited[kuna_row][kuna_column] == 1 && canReachBank == true ) {
            return true;
        }
        return false;
    }
};