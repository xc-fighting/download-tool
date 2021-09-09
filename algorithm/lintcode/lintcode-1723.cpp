class Solution {
public:
    /**
     * @param grid: a list of list
     * @param k: an integer
     * @return: Return the minimum number of steps to walk
     */
    int shortestPath(vector<vector<int>> &grid, int k) {
        // write your code here
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> memo( rows, vector<vector<int>>( cols, vector<int>(k+1,-1) ) );
        vector<vector<bool>> seen(rows,vector<bool>(cols,false));
        int ret = getMinimumDistance(grid,seen,memo,0,0,k);
        if(ret==INT_MAX)
        {
            return -1;
        }
        return ret;
    }

    int getMinimumDistance(vector<vector<int>>& grid,vector<vector<bool>>& seen,
                           vector<vector<vector<int>>>& memo,
                           int row,int col,int remain)
    {
        if(remain < 0)
        {
            return INT_MAX;
        }
        
        int rows = grid.size();
        int cols = grid[0].size();
        if( row == rows-1 && col == cols-1 )
        {
            return 0;
        }
        if(memo[row][col][remain] != -1)
        {
            return memo[row][col][remain];
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        seen[row][col] = true;
        int result = INT_MAX;
        for(int i=0;i<4;i++)
        {
            int newr = row + dx[i];
            int newc = col + dy[i];
            if(newr < 0 || newr >= rows || newc < 0 || newc >= cols
               || seen[newr][newc] == true )
            {
                continue;
            }
            if(grid[newr][newc] == 0)
            {
                int ret = getMinimumDistance(grid,seen,memo,newr,newc,remain);
                if(ret != INT_MAX)
                {
                    result = min(result, 1 + ret);
                }
            }
            else
            {
                int ret = getMinimumDistance(grid,seen,memo,newr,newc,remain-1);
                if(ret != INT_MAX)
                {
                    result = min(result, 1+ret);
                }
            }
        }
        seen[row][col] = false;
        memo[row][col][remain] = result;
        return result;
    }
};