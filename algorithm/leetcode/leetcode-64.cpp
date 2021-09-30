class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> memo(rows,vector<int>(cols,-1));
        return minSumStartFrom(memo,grid,0,0);
    }
    
    int minSumStartFrom(vector<vector<int>>& memo,
                        vector<vector<int>>& grid, 
                        int startRow, int startCol) {
       
        int rows = grid.size();
        int cols = grid[0].size();
         if( startRow < 0 || startRow >= rows 
             || startCol < 0 || startCol >= cols) {
             return INT_MAX;
         }
        if( startRow == rows - 1 && startCol == cols - 1 ) {
           
            return grid[rows-1][cols-1];
        }
        if( memo[startRow][startCol] != -1 ) {
            
            return memo[startRow][startCol];
        }
        int curVal = grid[startRow][startCol];
        int goRight =  minSumStartFrom(memo,grid,startRow,startCol+1);
        int goDown = minSumStartFrom(memo,grid,startRow+1, startCol);
        if( goRight != INT_MAX ) {
            goRight += curVal;
        }
        if( goDown != INT_MAX ) {
            goDown += curVal;
        }
        memo[startRow][startCol] = min(goRight,goDown);
        return memo[startRow][startCol];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> memo(rows,vector<int>(cols,-1));
        memo[0][0] = grid[0][0];
        for( int row = 1; row < rows; row++ ) {
            memo[row][0] = memo[row-1][0] + grid[row][0];
        }
        
        for( int col = 1; col < cols; col++ ) {
            memo[0][col] = memo[0][col-1] + grid[0][col];
        }
        
        for( int i = 1; i < rows; i++ ) {
            for( int j = 1; j < cols; j++ ) {
                int previous = min(memo[i-1][j],memo[i][j-1]);
                memo[i][j] = previous + grid[i][j];
            }
            
        }
        
        return memo[rows-1][cols-1];
    }
    
    
};