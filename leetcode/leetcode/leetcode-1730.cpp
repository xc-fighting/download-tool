#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;
class position
{
 public:
    int x;
    int y;
    bool operator==(const position& other) const
    {
        if(this->x == other.x && this->y == other.y)
        {
            return true;
        }
        return false;
    }
    position(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
class PositionHash
{
 public:
    size_t operator()(const position& instance) const
    {
        return instance.x * 1000 + instance.y;
    }
};


class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int startRow = -1;
        int startCol = -1;
        unordered_set<position,PositionHash> obstacles;
        unordered_set<position,PositionHash> foods;
        for(int i = 0; i < rows; i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == '*')
                {
                    startRow = i;
                    startCol = j;
                }
                else if(grid[i][j] == '#')
                {
                    position pos(i,j);
                    foods.insert(pos);
                }
                else if(grid[i][j] == 'X')
                {
                    
                    obstacles.insert(position(i,j));
                }
            }
        }
        int step = 0;
        queue<position> positionQueue;
        positionQueue.push(position(startRow,startCol));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(positionQueue.empty()==false)
        {
            int size = positionQueue.size();
            for(int i=0;i<size;i++)
            {
                position& topPos = positionQueue.front();
                positionQueue.pop();
                if(foods.find(topPos) != foods.end())
                {
                    return step;
                }
                for(int j=0;j<4;j++)
                {
                    int newr = topPos.x + dx[j];
                    int newc = topPos.y + dy[j];
                    if(newr < 0 || newr >= rows || newc < 0 || newc >= cols ||
                       obstacles.find(position(newr,newc)) != obstacles.end())
                    {
                        continue;
                    }
                    positionQueue.push(position(newr,newc));
                }
            }
            step++;
        }
        return -1;
    }
};

int main()
{

    return 0;
}


//memory issue:

struct position
{
 public:
    int x;
    int y;
    bool operator==(const position& other) const noexcept
    {
        if(this->x == other.x && this->y == other.y)
        {
            return true;
        }
        return false;
    }
    position(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
};
struct PositionHash
{
 public:
    size_t operator()(const position& instance) const
    {
        return instance.x * 1000 + instance.y;
    }
};


class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int startRow = -1;
        int startCol = -1;
        unordered_set<position,PositionHash> obstacles;
        unordered_set<position,PositionHash> foods;
        unordered_set<position,PositionHash> seen;
        for(int i = 0; i < rows; i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == '*')
                {
                    startRow = i;
                    startCol = j;
                }
                else if(grid[i][j] == '#')
                {
                    position pos(i,j);
                    foods.insert(pos);
                }
                else if(grid[i][j] == 'X')
                {
                    
                    obstacles.insert(position(i,j));
                }
            }
        }
      //  printf("finish here");
        int step = 0;
        queue<position> positionQueue;
        positionQueue.push(position(startRow,startCol));
        seen.insert(position(startRow,startCol));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(positionQueue.empty()==false)
        {
            int size = positionQueue.size();
            for(int i=0;i<size;i++)
            {
                position& topPos = positionQueue.front();
                positionQueue.pop();
                if(foods.find(topPos) != foods.end())
                {
                    return step;
                }
                for(int j=0;j<4;j++)
                {
                    int newr = topPos.x + dx[j];
                    int newc = topPos.y + dy[j];
                    if(newr < 0 || newr >= rows || newc < 0 || newc >= cols ||
                       obstacles.find(position(newr,newc)) != obstacles.end() ||
                       seen.find(position(newr,newc)) != seen.end())
                    {
                        continue;
                    }
                    positionQueue.push(position(newr,newc));
                    seen.insert(position(newr,newc));
                    cout<<"new pos"<<newr<<","<<newc<<endl;
                }
            }
            step++;
        }
        return -1;
    }
};


class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int startRow = -1;
        int startCol = -1;
        
        
        for(int i = 0; i < rows; i++)
        {
            bool find = false;
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == '*')
                {
                    startRow = i;
                    startCol = j;
                    find = true;
                    break;
                }
                
            }
            if(find)
            {
                break;
            }
        }
      //  printf("finish here");
        vector<vector<bool>> seen(rows,vector<bool>(cols,false));
        int step = 0;
        queue<pair<int,int>> positionQueue;
        positionQueue.push(pair<int,int>(startRow,startCol));
        seen[startRow][startCol] = true;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(positionQueue.empty()==false)
        {
            int size = positionQueue.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> topPos = positionQueue.front();
                positionQueue.pop();
                if(grid[topPos.first][topPos.second] == '#')
                {
                    return step;
                }
                for(int j=0;j<4;j++)
                {
                    int newr = topPos.first + dx[j];
                    int newc = topPos.second + dy[j];
                    if(newr < 0 || newr >= rows || newc < 0 || newc >= cols ||
                       grid[newr][newc] == 'X' ||
                       seen[newr][newc] == true )
                    {
                        continue;
                    }
                    positionQueue.push(pair<int,int>(newr,newc));
                    seen[newr][newc] = true;
                    //cout<<"new pos"<<newr<<","<<newc<<endl;
                }
            }
            step++;
        }
        return -1;
    }
};