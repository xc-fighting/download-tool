class Solution {
public:
    /**
     * @param carrot: an integer matrix
     * @return: Return the number of steps that can be moved.
     */
    int PickCarrots(vector<vector<int>> &carrot) {
        // write your code here
        int totalCarrot = 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int rows = carrot.size();
        int cols = carrot[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        int currentRow = (rows-1)/2;
        int currentCol = (cols-1)/2;
        visited[currentRow][currentCol] = true;
        totalCarrot += carrot[currentRow][currentCol];
        while(true)
        {
           int nextRow = -1;
           int nextCol = -1;
           for(int i=0;i<4;i++)
           {
               int x = currentRow + dx[i];
               int y = currentCol + dy[i];
               if( x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y] == true || carrot[x][y] == 0 )
               {
                   continue;
               }
               if( nextRow == -1 || carrot[x][y] > carrot[nextRow][nextCol] )
               {
                   nextRow = x;
                   nextCol = y;
               }
              
           }
           if(nextRow == -1)
           {
               break;
           }
           else
           {
               totalCarrot += carrot[nextRow][nextCol];
               visited[nextRow][nextCol] = true;
               currentRow = nextRow;
               currentCol = nextCol;
           }

        }
        return totalCarrot;
    }
};