class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int numDistinct = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> seen(rows, vector<bool>(cols, false));
        unordered_set<string> paths;
        for( int row = 0; row < grid.size(); row++ ) {
            
            for( int col = 0; col < grid[0].size(); col++ ) {
                
                if( grid[row][col] == 0 || seen[row][col] == true ) {
                    continue;
                }
                string path = "";
                traverse(grid, seen, &path, row, col);
              //  cout<<path<<endl;
                paths.insert(path);
            }
        }
        return paths.size();
    }
    
    void traverse( vector<vector<int>>& grid, vector<vector<bool>>& seen, string* path, int row, int col ) {
        
        string dir[4] = {"r","l","d","u"};
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
       // *path = *path + "0";
        seen[row][col] = true;
        for( int index = 0; index < 4; index++ ) {
            int newRow = row + dx[index];
            int newCol = col + dy[index];
            if( newRow < 0 || newRow >= grid.size() 
                || newCol < 0 || newCol >= grid[0].size() || grid[newRow][newCol] == 0 ||
                 seen[newRow][newCol] == true ) {
                
                continue;
            }
            *path = *path + dir[index];
            traverse(grid, seen, path, newRow, newCol);
            *path = *path + "*";
        }
        
        
    }
};