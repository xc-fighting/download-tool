class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // queue will keep track of info like (x,y,step_remain)
        if(grid.size()==1 && grid[0].size()==1)
        {
            return 0;
        }
        queue<vector<int>> pathQueue;
        vector<int> group(3,0);
        group[0] = 0;
        group[1] = 0;
        group[2] = k;
        pathQueue.push(group);
        int endx = grid.size()-1;
        int endy = grid[0].size() -1;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<bool>>> visited(rows,vector<vector<bool>>(cols,vector<bool>(k+1,false)));
        visited[0][0][k] = true;
        int step = 0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(pathQueue.empty() == false)
        {
            int size = pathQueue.size();
            for(int i=0;i<size;i++)
            {
                vector<int> head = pathQueue.front();
                pathQueue.pop();
                int curx = head[0];
                int cury = head[1];
                int remain = head[2];
                for(int j=0;j<4;j++)
                {
                    int newx = curx + dx[j];
                    int newy = cury + dy[j];
                    if(newx >=0 && newx < rows 
                       && newy >= 0 && newy < cols)
                    {
                       // cout<<step<<":"<<newx<<","<<newy<<endl;
                        if(newx == endx && newy == endy)
                        {
                            return step+1;
                        }
                        if(grid[newx][newy] == 1)
                        {
                            if(remain > 0)
                            {
                               if(visited[newx][newy][remain-1]==false)
                               {
                                   vector<int> newhead(3,0);
                                   newhead[0] = newx;
                                   newhead[1] = newy;
                                   newhead[2] = remain - 1;
                                   visited[newx][newy][remain-1] = true;
                                   pathQueue.push(newhead);
                               }
                               
                            }
                            
                        }
                        else
                        {
                            if(visited[newx][newy][remain]==false)
                            {
                                vector<int> newhead(3,0);
                                newhead[0]=newx;
                                newhead[1]=newy;
                                newhead[2]=remain;
                                visited[newx][newy][remain] = true;
                                pathQueue.push(newhead);
                            }
                           
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};


//TLE solution
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int res= getShortestPath(grid,visited,0,0,rows-1,cols-1,k);
        if(res == INT_MAX) {
            return -1;
        }
        return res;
    }
    
    int getShortestPath(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                        int row, int col, 
                        int targetRow, int targetCol, int removeLeft) {
        
        if( row == targetRow && col == targetCol ) {
            return 0;
        }
        
        int shortest = INT_MAX;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        visited[row][col] = true;
        for( int i = 0; i < 4; i++ ) {
            int newr = row + dx[i];
            int newc = col + dy[i];
            if( newr < 0 || newr >= grid.size() 
                || newc < 0 || newc >= grid[0].size()
                || visited[newr][newc] == true ) {
                
                continue;
            }
            if( grid[newr][newc] == 1 && removeLeft > 0 ) {
               
                int candidate = getShortestPath( grid, visited, newr, newc, targetRow, targetCol, removeLeft-1 );
                if(candidate != INT_MAX) {
                    shortest = min( shortest, 1 + candidate);
                }
                
            }
            
            if( grid[newr][newc] == 0 ) {
                
                int candidate = getShortestPath( grid, visited, newr, newc, targetRow, targetCol, removeLeft );
                if(candidate != INT_MAX) {
                    shortest = min( shortest, 1 + candidate);
                }
                
            }
        }
        visited[row][col] = false;
        return shortest;
        
    }
};



class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
       
        int steps = 0;
        vector<int> tuple(3,-1);
        tuple[0] = 0;
        tuple[1] = 0;
        tuple[2] = k;
        queue<vector<int>> pathQueue;
        int rows = grid.size();
        int cols = grid[0].size();
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        vector<vector<vector<bool>>> seen(rows,vector<vector<bool>>(cols,vector<bool>(k+1, false)));
        seen[0][0][k] = true;
        pathQueue.push(tuple);
       // cout<<"prepare to start"<<endl;
        while( pathQueue.empty() == false ) {
            int size = pathQueue.size();
          //  cout<<size<<endl;
            for( int i = 0; i < size; i++ ) {
                vector<int> frontElem = pathQueue.front();
                pathQueue.pop();
                int curRow = frontElem[0];
                int curCol = frontElem[1];
                if( curRow == rows - 1 && curCol == cols - 1 ) {
                    return steps;
                }
                int remain = frontElem[2];
               // cout<<"row:"<<curRow<<",col:"<<curCol<<",remain:"<<remain<<endl;
                for( int index = 0; index < 4; index++ ) {
                    int newRow = curRow + dx[index];
                    int newCol = curCol + dy[index];
                    
                    if( newRow < 0 || newRow >= rows 
                        || newCol < 0 || newCol >= cols ) {
                        
                        continue;
                    }
                    
                    if( grid[newRow][newCol] == 0  && seen[newRow][newCol][remain] == false ) {
                        seen[newRow][newCol][remain] = true;
                        vector<int> newElem(3,-1);
                        newElem[0] = newRow;
                        newElem[1] = newCol;
                        newElem[2] = remain;
                        pathQueue.push(newElem);
                        continue;
                    }
                    
                    if( grid[newRow][newCol] == 1 && remain > 0 && seen[newRow][newCol][remain-1] == false ) {
                        seen[newRow][newCol][remain-1] = true;
                        vector<int> newElem(3,-1);
                        newElem[0] = newRow;
                        newElem[1] = newCol;
                        newElem[2] = remain-1;
                        pathQueue.push(newElem);
                        continue;
                    }
                    
                }
            }
            steps++;
        }
        return -1;
    }
    
  
};