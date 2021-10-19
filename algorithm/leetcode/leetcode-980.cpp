class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startRow = -1;
        int startCol = -1;
        int endRow = -1;
        int endCol = -1;
        int remain = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for( int row = 0; row < grid.size(); row++ ) {
            for( int col = 0; col < grid[0].size(); col++ ) {
                if( grid[row][col] == 0 ) {
                    remain++;
                }
                if( grid[row][col] == 1 ) {
                    startRow = row;
                    startCol = col;
                }
                if( grid[row][col] == 2 ) {
                    endRow = row;
                    endCol = col;
                }
            }
        }
        
       
        return getPaths(grid,visited,startRow,startCol,endRow,endCol,remain+1);
    }
    
    int getPaths(vector<vector<int>>& grid, vector<vector<bool>>& visited, 
                 int row, int col, 
                 int targetRow, int targetCol, 
                 int remain) {
        
       // cout<<row<<","<<col<<endl;
        if( row == targetRow && col == targetCol ) {
         //   cout<<"find it:"<<remain<<endl;
            if( remain == 0 ) {
           //     cout<<"remain == 0"<<endl;
                return 1;
            }
            return 0;
        }
        int ways = 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        visited[row][col] = true;
        for( int index = 0; index < 4; index++ ) {
            int newr = row + dx[index];
            int newc = col + dy[index];
            if( newr < 0 || newr >= grid.size() || newc < 0 || newc >= grid[0].size() || visited[newr][newc] == true
               || grid[newr][newc] == -1 ) {
                continue;
            }
            ways += getPaths(grid,visited,newr,newc,targetRow,targetCol,remain-1);
        }
        visited[row][col] = false;
        return ways;
    }
};