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