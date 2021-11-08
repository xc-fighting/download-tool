class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int len = grid.size();
        vector<vector<int>> parent(len, vector<int>(len, -1));
        unordered_map<int,int> islandSize;
        for( int row = 0; row < len; row++ ) {
            for( int col = 0; col < len; col++ ) {
                 if( grid[row][col] == 1 ) {
                     if( parent[row][col] == -1 ) {
                          int id = row * len + col;
                          traverse(grid, parent,islandSize, row, col, id);
                     }
                     
                 }
            }
        }
        
        int result = 0;
        for( int row = 0; row < len; row++ ) {
            for(int col = 0; col < len; col++ ) {
                if( grid[row][col] == 0 ) {
                    unordered_set<int> indices;
                    int current = 0;
                    //check up
                    if( row > 0 && grid[row-1][col] == 1  ) {
                        indices.insert(parent[row-1][col]);
                    }
                    //check down
                    if( row < len - 1 && grid[row+1][col] == 1 ) {
                        indices.insert(parent[row+1][col]);
                    }
                    //check left
                    if( col > 0 && grid[row][col-1] == 1 ) {
                        indices.insert(parent[row][col-1]);
                    }
                    
                    //check right
                    if( col < len-1 && grid[row][col+1] == 1 ) {
                        indices.insert(parent[row][col+1]);
                    }
                    
                    for( auto id: indices ) {
                        current += islandSize[id];
                    }
                    current++;
                    result = max(result, current);
                }
            }
        }
        if( result == 0 ) {
            return len*len;
        }
        return result;
        
        
    }
    
    void traverse(vector<vector<int>>& grid, vector<vector<int>>& parent, 
                  unordered_map<int,int>& islandSize,
                  int row, int col, int id) {
        
         parent[row][col] = id;
         if(islandSize.find(id) == islandSize.end()) {
             islandSize[id] = 0;
         }
         islandSize[id]++;
         int dx[4] = {0,0,1,-1};
         int dy[4] = {1,-1,0,0};
         for( int index = 0; index < 4; index++ ) {
             int newr = row + dx[index];
             int newc = col + dy[index];
             if( newr >= 0 && newr < grid.size() && newc >= 0 
                 && newc < grid.size() && grid[newr][newc] == 1
                 && parent[newr][newc] == -1 ) {
                 traverse(grid,parent,islandSize,newr,newc,id);
             }
         }
         return;
    }
};
