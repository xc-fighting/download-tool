class Solution {
public:
    /**
     * @param grid: a 2d boolean array
     * @param k: an integer
     * @return: the number of Islands
     */
    int numsofIsland(vector<vector<bool>> &grid, int k) {
        // Write your code here
        unordered_set<int> seen;
        int result = 0;
        for( int row = 0; row < grid.size(); row++ ) {
            for( int col = 0; col < grid[0].size(); col++ ) {
                if( grid[row][col] == false ) {
                    continue;
                }
                int key = row* grid[0].size() + col;
                if(seen.find(key) == seen.end()) {
                    int islandSize = markIsland(grid,seen,row,col);
                   // cout<<"island start:"<<row<<","<<col<<","<<islandSize<<endl;
                    if( islandSize >= k ) {
                        result++;
                    }
                }
            }
        }
        return result;
    }

    int markIsland(vector<vector<bool>> &grid, unordered_set<int>& visited, int row, int col) {
        int islandSize = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        int key = row * cols + col;

        visited.insert(key);

        queue<int> states;
        states.push(key);

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while( states.empty() == false ) {
            int front = states.front();
            states.pop();
            islandSize++;
            int curRow = front / cols;
            int curCol = front % cols;
         //   cout<<"current:"<<curRow<<","<<curCol<<endl;
            for( int index = 0; index < 4; index++ ) {

                 int newRow = curRow + dx[index];
                 int newCol = curCol + dy[index];

                 int newKey = newRow*cols + newCol;
              //   cout<<"pos:"<<newRow<<","<<newCol<<endl;
                 if( newRow >= 0 && newRow < rows 
                     && newCol >= 0 && newCol < cols 
                     && grid[newRow][newCol] == true
                     && visited.find(newKey) == visited.end() ) {
                    //     cout<<"new:"<<newRow<<","<<newCol<<endl;
                         visited.insert(newKey);
                         states.push(newKey);
                     }
            }
        }

        return islandSize;
    }
};