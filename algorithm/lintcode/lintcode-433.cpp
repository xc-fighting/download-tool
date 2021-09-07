class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        int result = 0;
        unordered_set<string> visited;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == true && visited.find(to_string(i)+":"+to_string(j)) == visited.end())
                {
                    result++;
                    traverse(grid,i,j,visited);
                }
            }
        }
        return result;
    }

    void traverse(vector<vector<bool>> &grid,int row,int col,unordered_set<string>& visited)
    {
        int dx[4] ={0,0,1,-1};
        int dy[4] ={1,-1,0,0};
        string key = to_string(row)+":"+to_string(col);
        visited.insert(key);
        for(int i=0;i<4;i++)
        {
            int newr = row+dx[i];
            int newc = col + dy[i];
            string newkey = to_string(newr) +":"+to_string(newc);
            if(newr >=0 && newr < grid.size() 
               && newc >=0 && newc<grid[0].size() 
               && grid[newr][newc] == true 
               && visited.find(newkey) == visited.end())
            {
                traverse(grid,newr,newc,visited);
            }
        }
        return;
    }
};